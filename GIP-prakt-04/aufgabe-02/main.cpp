#include <iostream>
#include <string>

using namespace std;

int main(){

    int sudoku[9][9];

    //reading the sudoku as string
    cout << "Bitte geben Sie das Sudoku ein:" << endl;
    string eingabe[11] = {};
    for(int i=0; i<11;i++){
        cin >> eingabe[i];
    }
    

    // removing . and | from the string
    string eingabe_new[11];
    for(int i=0;i<11;i++){
            for(int j=0;j<eingabe[i].length();j++){
                if(eingabe[i].at(j) >= '0' && eingabe[i].at(j) <= '9'){
                    eingabe_new[i]+=eingabe[i].at(j);
                    }
                        
            }
        }

    // removing empty lines from the array
    string eingabe_final[9];
        int z = 0;
        for(int j=0; j<11;j++){
            if(j==3 or j==7)
                continue;
            else{
                eingabe_final[z] = eingabe_new[j];
                z+=1;
                
            }

        }


    
    // converting string array to int 
    int a = 0;
    for(int i=0; i<9;i++,a++){
        int c = 0;
        for(int j =0; j<9;j++){
            sudoku[a][c] = (int)eingabe_final[i][j] - 48;
                c++;
        }

    }
       
    // cout << "\n";
    // for (int i=0;i<9;i++){
    //     cout << eingabe_final[i] << endl;
    // }
    
    // cout << endl;
    // for(int i = 0;i<9;i++){
    //     for(int j=0; j<9;j++){
    //         cout << sudoku[i][j];
    //     }
    //     cout << endl;
    // }
    

//printing the sudoku with new signs

cout << "Das Sudoku lautet:" << endl;

for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        cout << ";" << sudoku[i][j];
        if(j==2 || j==5){
            cout << ";//";
        }

    }
    cout << endl;
    if(i==2 || i==5){
        cout << "=======//=======//=======" << endl;
    }

}



system("PAUSE");
return 0;





}