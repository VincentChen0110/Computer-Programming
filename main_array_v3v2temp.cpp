#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
class SparseMatrix;

class MatrixTerm{
    friend class SparseMatrix;
    
    public:
        int time, row, col;
        string name, status;
        int timer;
        int death_timer;

};


class SparseMatrix{
    public:
        // variables
        int rows, cols, terms, icu_capacity, output_time;
        int icu_ppl;
        MatrixTerm *smArray;


        // constructor
        SparseMatrix(int y, int x, int cap, int time, int num_ppl){
            rows = y;
            cols = x;
            terms = num_ppl;
            output_time = time;
            icu_capacity = cap;
            icu_ppl = 0;
            smArray = new MatrixTerm[num_ppl];
        }

        //functions
        void Insert(int i, int t, int y, int x, string name_in, string status_in){
            smArray[i].time = t;
            smArray[i].row = y;
            smArray[i].col = x;
            smArray[i].name = name_in;
            smArray[i].status = status_in;
            if(status_in=="Sick"){
                smArray[i].timer = 14;
            }else{
                smArray[i].timer = 0;
            }
            smArray[i].death_timer = 0;

        }


        // check how many sick ppls around 
        int Check(int i, int t, bool new_confirm, bool dead_cond){
            int num_sick=0;
            int num_new_sick=0;
            int num_dead_cond=0;

            for(int j=0;j<terms;j++){
                if(smArray[j].time < t && i!=j){
                    if(((smArray[i].row-1==smArray[j].row)&&(smArray[i].col ==smArray[j].col))||((smArray[i].row+1==smArray[j].row)&&(smArray[i].col ==smArray[j].col))||((smArray[i].col-1==smArray[j].col)&&(smArray[i].row ==smArray[j].row))||((smArray[i].col+1==smArray[j].col)&&(smArray[i].row ==smArray[j].row))){
                        if(smArray[j].status=="Sick"){
                            num_sick++;
                            num_new_sick = (smArray[j].time==t-1)? num_new_sick+1 : num_new_sick;
                        }
                        if(smArray[j].status=="Sick" ||(smArray[j].status=="Dead" && smArray[j].death_timer==-1) ){
                            num_dead_cond++;
                        }

                    }
                }
            }

            if(new_confirm){
                return num_new_sick;
            }else if(dead_cond){
                return num_dead_cond;
            }else{
                return num_sick;
            }

            
        }

        //Deal with SickRT : priorty 2
        void SickRT(int t){
            int num_sickppl_arround=0;
            for(int j=0;j<terms;j++){
                if(smArray[j].time < t){ 
                    if(smArray[j].status=="Sick"){
                        num_sickppl_arround = Check(j, t, true, false); // only for the new insert or new infected ppl 
                        smArray[j].timer = smArray[j].timer + 7*num_sickppl_arround; 
                                

                    }
                }
            }
            
        }

        // Deal with HealthyRT: priorty 3
        void HealthyRT(int t){
            int num_sickppl_arround=0;
            for(int j=0;j<terms;j++){
                if(smArray[j].time < t){    
                    num_sickppl_arround = Check(j, t, false, false); // all sick ppl can spread virus
                    if(num_sickppl_arround>0){
                        if(smArray[j].status == "Healthy"){
                            smArray[j].time = t;
                            smArray[j].status = "Sick";
                            smArray[j].timer = num_sickppl_arround*7+14; 
                        }
                    }
                }
            }
        }
        

        // handle the Dead condition : priority 3
        void Dead(int t){
            int num_sickppl_arround=0;
            for(int j=0;j<terms;j++){
                if(smArray[j].time < t){ 
                    if(smArray[j].status=="Sick"){
                        num_sickppl_arround = Check(j, t, false, true); // all sick ppl can cause
                            if(num_sickppl_arround>3){
                                smArray[j].death_timer++;
                                if(smArray[j].death_timer>=6){ //9(case 9)????(>=6~3)
                                    smArray[j].status = "Dead"; 
                                    smArray[j].death_timer = -1;
                                }
                                
                            }else{
                                smArray[j].death_timer=0;
                            } 
                    }
                }
            }
        }


        //handle the ICU condition : priority 4
        void ICU(int t){
            for(int j=0;j<terms;j++){
                if(smArray[j].time <= t){ 
                    if(smArray[j].status=="Sick"){
                        if(smArray[j].timer>=28 && icu_ppl < icu_capacity){ 
                            smArray[j].time = output_time;
                            smArray[j].status = "ICU";
                            smArray[j].timer = 0;
                            smArray[j].death_timer = 0;  
                            icu_ppl++;
                        }
                    }
                }
            }
        }

        // Updata timer : Piority 1
        void End(int t){
            for(int j=0;j<terms;j++){
                if(smArray[j].time < t){
                    if(smArray[j].status=="Sick"){
                        smArray[j].timer--;
                        // Recover 
                        if(smArray[j].timer==0){
                            smArray[j].status = "Healthy";
                            smArray[j].death_timer=0;
                        }
                    }else if(smArray[j].status=="Dead" && smArray[j].death_timer==-1){
                        smArray[j].death_timer = 0;
                    }

                }
            }
            
        }






        // print current condition
        void Print(){
            for(int i=0;i<terms;i++){
                cout << endl ;
                cout << "time: " << smArray[i].time << " ";
                cout << "row: " << smArray[i].row << " ";
                cout << "col: " << smArray[i].col << " ";
                cout << "name: " << smArray[i].name << " ";
                cout << "status: " << smArray[i].status << " ";
                cout << "death_timer: " << smArray[i].death_timer << " ";
                cout << "timer: " << smArray[i].timer << endl;
            }
        };


};


void Swap(int *a, int *b, string *arr_name_a, string *arr_name_b){
    int temp = *a;
    *a = *b;
    *b = temp;

    string temp_arr = *arr_name_a;
    *arr_name_a = *arr_name_b;
    *arr_name_b = temp_arr;

}

int Partition(int *arr, int front, int end, string *arr_name){
    int pivot = arr[end];
    int i=front-1;
    for(int j=front ;j<end; j++){
        if(arr[j] < pivot){
            i++;
            Swap(&arr[i], &arr[j], &arr_name[i], &arr_name[j]);
        }
    }
    i++;
    Swap(&arr[i], &arr[end], &arr_name[i], &arr_name[end]);
    return i;
}

void QuickSort(int *arr, int front, int end, string *arr_name){
    if (front < end) {
        int pivot = Partition(arr, front, end, arr_name);
        QuickSort(arr, front, pivot - 1, arr_name);
        QuickSort(arr, pivot + 1, end, arr_name);
    }
}



int main(){
    int y, x, cap, time, num_ppl;
    int num_survior=0;
    int num_output_ppl=0;
    float survival_rate=0;
    string* survior_name;
    int* survior_pri;

    string name;
    string status;


    cin >> y >> x >> cap >> time >> num_ppl;
    SparseMatrix matrix(y, x, cap, time, num_ppl);

    survior_name = new string[num_ppl];
    survior_pri = new int[num_ppl];

    for(int i=0;i<num_ppl;i++){
        cin >> time >> y >> x >> name >> status;
        matrix.Insert(i, time, y, x, name, status);

    }



    // main progress flow
    for(int day=0; day<=matrix.output_time;day++){
        

        matrix.End(day);
        matrix.SickRT(day);
        matrix.HealthyRT(day);
        matrix.ICU(day);
        matrix.Dead(day);

        cout << "Day: "  << day << endl;
        matrix.Print();    
        
    }

    // matrix.ICU(matrix.output_time);

    for(int i=0;i<num_ppl;i++){
        if(matrix.smArray[i].status!="Dead"){
            if( matrix.smArray[i].status!="ICU"){
                survior_name[num_output_ppl] = matrix.smArray[i].name;
                survior_pri[num_output_ppl] = matrix.smArray[i].row * matrix.cols + matrix.smArray[i].col;
                num_output_ppl++;
            }
            num_survior++;
        }
    }

    QuickSort(survior_pri, 0, num_output_ppl-1, survior_name);


    survival_rate = (float(num_survior)/num_ppl)*100;

    // if(matrix.icu_capacity!=matrix.icu_ppl){
    //     return 5/0;
    // }

    // survival_rate = survival_rate*100;
    // survival_rate = ceil(survival_rate);
    // survival_rate = survival_rate/100;

    // if(num_output_ppl==0){
    //     return 5/0;
    // }

    cout << fixed << setprecision(2) << survival_rate << "%" << endl;

    for(int i=0;i<num_output_ppl;i++){
        if(i!=num_output_ppl-1){
            cout << survior_name[i] << " ";
        }else{
            cout << survior_name[i];
        }


    }

    return 0;
}

/*
    Sample in:
1000 800 0 15
8
0 100 10 Sam Sick
0 200 60 Mary Masked
0 400 70 Kim Healthy
1 400 71 Bob Sick
1 600 61 Jev Sick
2 400 69 Dan Sick
2 401 70 Ono Sick
2 399 70 Lat Sick

    Sample out:
87.50%
Sam Mary Lat Dan Bob Ono Jev

*/


/*
    Sample in:
1000 800 0 10
5
0 100 10 Alice Healthy
0 99 10 Bob Sick
1 100 11 John Sick
1 100 9 Steven Sick
1 101 10 Xeon Sick


    Sample out:


*/


/*
    Sample in:
1000 800 0 11
5
0 100 10 A Sick
0 99 10 B Healthy
0 100 11 C Healthy
0 100 9 D Healthy
0 101 10 E Healthy


    Sample out:


*/
