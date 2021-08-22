#include<stdio.h>
#include<conio.h>
#include<string.h>
#define array_size 50
enum Operator{E= -1/*no oeprator*/,ADD,MIN,MUL,DIV,REM};
int isdigit(char c) {
    return c>='0'&&c<='9';
}

//get int from char
int getnum(char c) {
    if(isdigit(c)) {
        return   c-'0';
    }
    return -1;
}

int main() {
	int pos=0;
    int num1, num2,op=E, res,
	innum1,
	innum2;
    char choice[array_size]="";
    {
start:
//reset variables
        innum1=0;
        innum2=0;
        op=-1;
        num2=0;
        num1=0;
		res=0;
		for(int i=0;i<array_size;i++){
		choice[i]=' ';
		}//reset variables ends
		//get user input
		printf("\n->");
		fgets(choice,array_size,stdin);
		choice[strlen(choice)-1]='\0';//remove new line
		//check if user write command
		if (!strcmp(choice ,"exit")||!strcmp(choice ,"q")){
			printf("exit");
			return 0;
		}else if(!strcmp(choice ,"cls")||!strcmp(choice ,"clear"))
		{
			system("cls");
			goto start;
		}

        for(pos=0; pos<array_size; pos++) {
            char thischar=choice[pos];
			//read operator and goto set_num to stop read first number if it 
			//still reading
            if(thischar=='+') {
                op=ADD;
                goto set_num;
            }else
            if(thischar=='-') {
                op=MIN;
                goto set_num;
            }else
            if(thischar=='/') {
                op=DIV;
                goto set_num;
            }else
            if(thischar=='*') {
                op=MUL;
                goto set_num;

            }else if(thischar=='%'){
				op=REM;
				goto set_num;
			}

            if(thischar==' '||thischar=='\0') {
set_num://this label to end reading number
                if(innum1==1) {//if reading num 
                    innum1=2;//stop read 
                } else if(innum2==1) {
                    innum2=2;
                }
                continue;
            } else if(isdigit(thischar)) {
                if(innum1==1||innum1==0) {//continue read num1 or start read it  
                    innum1=1;//set it reading if it just start 
					//add selected cahr to num
                    num1=num1*10;
                    num1+= getnum((int)choice[pos]);

                } else if(innum2==1||innum2==0) {
                    innum2=1;
                    num2=num2*10;
                    num2+= getnum(choice[pos]);

                }
            } else {//if it notvaild letter (not space or digit or operator)
				printf("unvaild letter\n");
				printf("{%s}",choice);
				printf("\n");
			for(int i = 0 ; i < pos ;i++){printf("-");}
				printf("^");
                
            goto start;}
        }
        //get result
        if(op==E) {
            printf("eror: no operator");
            goto start;
        } else if(op==ADD) {
            res=num1+num2;
        } else if(op==MIN) {
            res=num1-num2;
        } else if(op==DIV) {
            if(num2!=0) {
                res=num1/num2;
            } else {
				printf("math eror:cannot div by zero");
                goto start;
            }
        } else if(op==MUL) {
            res=num1*num2;
        }else if(op==REM){
			res=num1%num2;
		}
        printf("\nresult=%d\n",res);

        goto start;
        return 0;
    }

}
