#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'},
                   {'4', '5', '6'},
                   {'7', '8', '9'}};
int row;
int column;
char token = 'x';
bool tie = false;
string p1, p2;

void Function1(){
cout<<"    |     |\n";
cout<<" "<<space[0][0]<<"  |  "<<space[0][1]<<"  | "<<space[0][2]<<"  \n";
cout<<"____|_____|____\n";
cout<<"    |     |\n";
cout<<" "<<space[1][0]<<"  |  "<<space[1][1]<<"  | "<<space[1][2]<<"  \n";
cout<<"____|_____|____\n";
cout<<"    |     |\n";
cout<<" "<<space[2][0]<<"  |  "<<space[2][1]<<"  | "<<space[2][2]<<"  \n";
cout<<"    |     |\n";
}

void Function2(){
    int digit;

    if(token == 'x'){
        cout<<p1<<" please enter 'x': ";
        cin>>digit;
    }
    if(token == 'o'){
        cout<<p2<<" please enter 'o': ";
        cin>>digit;
    }

    if(digit == 1){
        row = 0;
        column = 0;
    }
    if(digit == 2){
        row =0;
        column = 1;
    }
    if(digit == 3){
        row =0;
        column = 2;
    }
    if(digit == 4){
        row =1;
        column = 0;
    }
    if(digit == 5){
        row =1;
        column = 1;
    }
    if(digit == 6){
        row =1;
        column = 2;
    }
    if(digit == 7){
        row =2;
        column = 0;
    }
    if(digit == 8){
        row =2;
        column = 1;
    }
    if(digit == 9){
        row =2;
        column = 2;
    }
   else
   cout<<"Invalid!!!!"<<endl;

   if(token == 'x' && space[row][column] != 'x' && space[row][column] != 'o'){
   space[row][column] = 'x';
   token = 'o';
   }
   else if(token == 'o' && space[row][column] != 'x' && space[row][column] != 'o'){
   space[row][column] = 'o';
   token = 'x';
   }

   else if(digit < 1 || digit > 9){
    cout<<"There is no empty space!"<<endl;
    Function2();
   }
Function1();
}
    bool Function3(){

        for(int i = 0;i < 3;i++){
            if(space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]){
             return true;
            }
        }
        if(space[0][0] == space[1][1] && space[0][0] == space[2][2] || space[0][2] == space[1][1] && space[0][2] == space[2][0]){
            return true;
        }

        for(int i = 0;i < 3;i++)
        {
            for(int j =0;j < 3;j++){
                if(space[i][j] != 'x' && space[i][j] != 'o'){
                    return false;
                }
            }
        }
    tie = true;
    return true;    
}
int main(){
int count = 0;
cout<<"Enter the name of the first player: \n";
getline(cin, p1);

cout<<"Enter the name of the second player: \n";
getline(cin, p2);
cout<<p1<<" will play first\n";


while(!Function3())
{
    Function1();
    Function2();
    Function3();
    cout<<endl;
}
if(token == 'x' && tie == false){
cout<<p2<<" wins"<<endl;
}

else if(token == 'o' && tie == false){
cout<<p1<<" wins"<<endl;
}

else if(tie == true){
    cout<<"Draw!!!"<<endl;
}

    return 0;
}
