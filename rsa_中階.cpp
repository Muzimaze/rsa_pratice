//大數運算 
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<ctime>
using namespace std;

string remove_0(string);

int longer(int, int);

bool Is_A_Bigger_Than_B(string, string);

string str_pow(string, int);

string O_divide_for_Remain(string, string);

string O_divide_for_Quotient(string, string);

string O_minus(string, string);

string O_multiply(string, string);

string O_plus(string, string);

string binary(string);
 
int main(){
	cout<<"rsa作業 by 10510137李孟軒"<<endl<<"--------------------------------"<<endl;
	string text= "RSA INVOLVES A PUBLIC KEY AND A PRIVATE KEY THE PUBLIC KEY CAN BE KNOWN BY EVERYONE AND IS USED FOR ENCRYPTION MESSAGES MESSAGES ENCRYPTED WITH THE PUBLIC KEY CAN BE ONLY BE DECRYPTED IN A REASONABLE AMOUNT OF TIME USING THE PRIVATE KEY THE KEYS FOR THE RSA ALGORITHM ARE GENERATED THE FOLLOWING WAY", temp_str;
	int length=ceil(text.length()/2);
	stringstream ss;
	string remain="1";	
	string M[length+1], C[length+1], A[length+1];
	int M_NUM[length+1][2];
	string p="3896519873";
	string q="6728380129";
	string n="26217266885746803617";
	string e="7237327049";
	string d="4962162255038558585";
	for(int i=0;i<=length;i++){
		M[i]=temp_str.assign(text,i*2,2);
	}
	
	cout<<setw(5)<<"p="<<p<<endl<<setw(5)<<"q="<<q<<endl<<setw(5)<<"n="<<n<<endl<<setw(5)<<"e="<<e<<endl<<setw(5)<<"d="<<d<<endl;

	for(int i=0;i<=length;i++){
		M_NUM[i][0]=(M[i][0]-'0'-17);
		if(M_NUM[i][0]<0)	M_NUM[i][0]=26;
		M_NUM[i][1]=(M[i][1]-'0'-17);
		if(M_NUM[i][1]<0)	M_NUM[i][1]=26;
		M_NUM[i][0]=M_NUM[i][0]*100+M_NUM[i][1];
		ss<<M_NUM[i][0];
		ss>>M[i];
		ss.clear();
	}
	cout<<setw(5)<<"M="<<endl;
	for(int i=0;i<=length;i++){
		cout<<setw(10)<<M_NUM[i][0];
	}
	cout<<endl;
	int length_02_e, length_02_d;
	string str_02_e=binary(e);
	string str_02_d=binary(d);
	length_02_e=str_02_e.length();
	length_02_d=str_02_d.length();
		
	cout<<setw(5)<<"C="<<endl;
	for(int k=0;k<=length;k++){
		for(int i=length_02_e-1;i>=0;i--){
			if(str_02_e[i]=='1'){
				remain=O_multiply(remain, remain);
				remain=O_multiply(remain, M[k]);
				
			}
			else{
				remain=O_multiply(remain,remain);
			}
			
			remain=O_divide_for_Remain(remain, n);
		}
		C[k]=remain;
		cout<<setw(25)<<C[k]<<endl;
		remain="1";
	}
	cout<<setw(5)<<"M="<<endl;


	for(int k=0;k<=length;k++){
		for(int i=length_02_d-1;i>=0;i--){
			if(str_02_d[i]=='1'){
				remain=O_multiply(remain, remain);
				remain=O_multiply(remain, C[k]);
				
			}
			else{
				remain=O_multiply(remain,remain);
			}
			
			remain=O_divide_for_Remain(remain, n);
		}
		C[k]=remain;
		cout<<setw(10)<<C[k];
		remain="1";
	}
	cout<<endl<<setw(5)<<"共花費"<<(double)clock() / CLOCKS_PER_SEC <<"秒"<<endl;
	system("pause");
}














string binary(string str_10){
	int interval, remainder=0, num_quo, length;
	string str_temp, quotient, str_binary, num[10]={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	
	while(Is_A_Bigger_Than_B(str_10,"2")==1){
	length=str_10.length();
		for(int i=0;i<length;i++){
			remainder=remainder*10+atoi(str_temp.assign(str_10,i,1).c_str());
			quotient+=num[remainder/2];
			remainder=remainder%2;
			}
		str_10=quotient;
		quotient.clear();
		str_binary+=num[remainder];
		remainder=0;
	}
	str_binary+=num[atoi(str_10.c_str())];
	return str_binary;
	
}


string remove_0(string str_0){
	int i=0, length=str_0.length();
	string temp;
	while(str_0[i]=='0' && i<length-1){
		i++;
	}
	temp=temp.assign(str_0,i,length-i);
	return temp;
}

int longer(int longer_a,int longer_b){
	if(longer_a>=longer_b)	return longer_a;
	else return longer_b;
}

bool Is_A_Bigger_Than_B(string str_a,string str_b){
	int lengthA=str_a.length(), lengthB=str_b.length(), length=longer(lengthA,lengthB),deviation=2*length-lengthB-lengthA;	
		if(lengthA==lengthB){
			for(int i=0;i<length ;i++){
				if(str_a[i]!=str_b[i]){
					if(int(str_a[i])>int(str_b[i]))	return true;
					else	return false;
				}
			}							
		}
		else if(lengthA>lengthB){
			for(int i=0;i<deviation ;i++)	str_b+="0";
			for(int i=0;i<length ;i++){
				if(str_a[i]!=str_b[(i+lengthB)%length]){
					if(int(str_a[i])>int(str_b[(i+lengthB)%length]))	return true;
					else	return false;
				}
			}			
		}	
		else if(lengthB>lengthA){
			for(int i=0;i<deviation ;i++)	str_a+="0";
			for(int i=0;i<length ;i++){
				if(str_a[(i+lengthA)%length]!=str_b[i]){
					if(int(str_a[(i+lengthA)%length])>int(str_b[i]))	return true;
				else	return false;
				}
			}
			
		}
		if(str_a[lengthA-1]==str_b[lengthB-1])	return true;
		cout<<"error";
}

//-------------------------------------------------------------------

string O_plus(string add_A, string add_B){
	int interval=(longer(add_A.length(),add_B.length())/4)+1;
	string str_A, str_B, add_str[interval], temp, str_Ans;
	int add_int[3][interval], addadd[interval];
	stringstream ss[interval];
	for(int i=0;i<interval;i++){
	addadd[i]=0;	
	}
	
	for(int i=0;i<(interval*4-add_A.length());i++){
	str_A+="0"; 	
	}	
	str_A+=add_A;
	for(int i=0;i<(interval*4-add_B.length());i++){
	str_B+="0"; 	
	}
	str_B+=add_B;
	for(int i=0;i<interval;i++){
		add_int[0][i]=atoi(temp.assign(str_A,i*4,4).c_str());
		add_int[1][i]=atoi(temp.assign(str_B,i*4,4).c_str());		
	}
	

	
	
	for(int i=interval-1;i>=0;i--){
		add_int[2][i]=add_int[0][i]+add_int[1][i];
		if(i!=interval-1){		
			if(addadd[i+1]==1){
				add_int[2][i]++;
			}
		}
		if(add_int[2][i]>9999){
			add_int[2][i]-=10000;	addadd[i]++;
		}	
	}	
	

	
	for(int i=0;i<interval;i++){
		ss[i] <<add_int[2][i];
		ss[i] >>temp;
		
		for(int j=0;j<(4-temp.length());j++){
			add_str[i]+="0";	
		}
		add_str[i]+=temp;
	}
	
	
		for(int i=0;i<interval;i++){
			str_Ans+=add_str[i];
		}
	str_Ans=remove_0(str_Ans);
	return str_Ans;
}
//------------------------------------------------------------

string O_minus(string minus_A, string minus_B){
	int length_A=minus_A.length(), length_B=minus_B.length();
	int interval=(longer(length_A,length_B)/8)+1;
	string str_A, str_B, minus_str[interval], temp, str_Ans;
	long long minus_int[2][interval], minusminus=0;
	stringstream ss[interval];
	
	for(int i=0;i<(interval*8-length_A);i++){
	str_A+="0"; 	
	}	
	str_A+=minus_A;
	for(int i=0;i<(interval*8-length_B);i++){
	str_B+="0"; 	
	}
	str_B+=minus_B;
	for(int i=0;i<interval;i++){
		minus_int[0][i]=atoi(temp.assign(str_A,i*8,8).c_str());
		minus_int[1][i]=atoi(temp.assign(str_B,i*8,8).c_str());		
	}
	
	for(int i=interval-1;i>=0;i--){
		minus_int[0][i]-=minus_int[1][i];
		if(i!=interval-1){		
			if(minusminus!=0){
				minus_int[0][i]--;
				minusminus=0;
			}
		}
		if(minus_int[0][i]<0){
			minus_int[0][i]+=100000000;	minusminus--;
		}	
	}	
	

	
	for(int i=0;i<interval;i++){
		ss[i] <<minus_int[0][i];
		ss[i] >>temp;
		
		for(int j=0;j<(8-temp.length());j++){
			minus_str[i]+="0";	
		}
		minus_str[i]+=temp;
	}
		for(int i=0;i<interval;i++){
			str_Ans+=minus_str[i];
		}
	str_Ans=remove_0(str_Ans);
	return str_Ans;
}

//------------------------------------------------------------

string O_multiply(string multiply_A, string multiply_B){
	int lengthA=multiply_A.length(), lengthB=multiply_B.length(), interval=(lengthA+lengthB)/8+1;
	string str_A, str_B, multiply_str[interval], temp, str_Ans;
	long long multiply_int[3][interval], multiplymultiply=0;
	stringstream ss[interval];
	
	for(int i=0;i<interval;i++){
		multiply_int[2][i]=0;	
	}

	for(int i=0;i<(interval*8-lengthA);i++){
	str_A+="0"; 	
	}	
	str_A+=multiply_A;
	for(int i=0;i<(interval*8-lengthB);i++){
	str_B+="0"; 	
	}
	str_B+=multiply_B;
	for(int i=0;i<interval;i++){
		multiply_int[0][i]=atoi(temp.assign(str_A,i*8,8).c_str());
		multiply_int[1][i]=atoi(temp.assign(str_B,i*8,8).c_str());		
	}
	
	for(int i=interval-1;i>=0;i--){
		for(int j=interval-1;j>=0;j--){
			multiply_int[2][i+j-interval+1]+=multiply_int[0][i]*multiply_int[1][j];
		}
	}
	

	
	for(int i=interval-1;i>=0;i--){
		if(i!=interval-1){		
			if(multiplymultiply!=0){
				multiply_int[2][i]+=multiplymultiply;
				multiplymultiply=0;
			}
		}				
		if(multiply_int[2][i]>99999999){
			multiplymultiply=multiply_int[2][i]/100000000;	multiply_int[2][i]%=100000000;
		}	
	}	
	
	for(int i=0;i<interval;i++){
		ss[i] <<multiply_int[2][i];
		ss[i] >>temp;
		
		for(int j=0;j<(8-temp.length());j++){
			multiply_str[i]+="0";	
		}
		multiply_str[i]+=temp;
	}
		for(int i=0;i<interval;i++){
			str_Ans+=multiply_str[i];
		}
	str_Ans=remove_0(str_Ans);
	return str_Ans;
}

//----------------------------------------------------------

string O_divide_for_Remain(string divide_A, string divide_B){
	int interval=divide_A.length()-divide_B.length();
	string str_temp, str_remainder; 

	str_remainder=str_temp.assign(divide_A,0,divide_B.length());
				
	for(int i=0;i<interval+1;i++){
		for(int j=1;j<10;j++){
		if(Is_A_Bigger_Than_B(str_remainder,divide_B)==1){
			str_remainder=O_minus(str_remainder,divide_B);
		}
		else{
			break;
		}
			}
				str_remainder+=str_temp.assign(divide_A,divide_B.length()+i,1);
	}		
	
	str_remainder=remove_0(str_remainder);
	return str_remainder;
	
}

string O_divide_for_Quotient(string divide_A, string divide_B){
	int interval=divide_A.length()-divide_B.length();
	string str_temp, str_remainder, quotient, num[10]={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	
	str_remainder=str_temp.assign(divide_A,0,divide_B.length());
				
	for(int i=0;i<interval+1;i++){
		for(int j=1;j<10;j++){
		if(Is_A_Bigger_Than_B(str_remainder,divide_B)==1){
			str_remainder=O_minus(str_remainder,divide_B);
		}
		else{
			quotient+=num[j-1];
			break;
		}
			}
				str_remainder+=str_temp.assign(divide_A,divide_B.length()+i,1);
				
	}		

	quotient=remove_0(quotient);
	return quotient;
	
}

//--------------------------------------------------

string str_pow(string str_pow,int to_m){
	string initial_str=str_pow, ans_str;
	int times=0, temp=2, remain=to_m;
	
	
	while(remain>0){
	while(remain>temp){
		times++;
		temp=temp*2;
	}

	for(int i=0;i<times;i++){
		initial_str=O_multiply(initial_str, initial_str);
	}
	if(remain==to_m)	ans_str=initial_str;
	else{
		ans_str=O_multiply(ans_str, initial_str);
	}
	remain-=temp/2;
	initial_str=str_pow;
	temp=2;
	times=0;
	}	

	return ans_str;
}



//---------------------------------------------------------------

