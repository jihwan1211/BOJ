#include<bits/stdc++.h>
using namespace std;

string str;
// 모음이 등장?
bool flag, result;
int jcnt, mcnt;
char pprev;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   do{
      cin>>str;
      if(str == "end") break;
      flag=false; jcnt=0; mcnt=0; result=true; pprev = 'a';
      for(int i=0; i<str.length(); i++){
         if(jcnt==3 || mcnt==3) { result = false; break;}
         if(i>0 && pprev == str[i]) {
            if(str[i] == 'e' || str[i] == 'o') {}
            else{result = false; break;}
         }
         if(str[i]=='a' || str[i] == 'e' || str[i] == 'i' || str[i]=='o' || str[i] == 'u'){
            flag=true;
            jcnt=0;
            mcnt+=1;
         }else{
            jcnt+=1;
            mcnt=0;
         }
         pprev=str[i];
      }
       if(jcnt==3 || mcnt==3) { result = false;}
      if(result && flag){
         cout<<"<"<<str<<">"<<" is acceptable."<<"\n";
      } else{
         cout<<"<"<<str<<">"<<" is not acceptable."<<"\n";
      }
   }while(str != "end");
   return 0;
}