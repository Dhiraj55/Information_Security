 #include<bits/stdc++.h> 
using namespace std; 
int main(){ 
int x;string s;string s1; 
while(1){ 
cout<<"1 : encryption"<<endl; 
cout<<"2 : decryption"<<endl; 
cout<<"3 : exit"<<endl<<endl; 
cin>>x; 
switch(x) 
{ 
case 1: 
cout<<"enter Plaintext : "; 
cin>>s; 
int key; 
cout<<"enter key : "; 
cin>>key; 
for(int i=0;i<s.length();i++){ 
if(s[i]>64&&s[i]<91){ 
s[i]=('A'+(s[i]-'A'+key)%26); 
} 
if(s[i]>96&&s[i]<123){ 
s[i]=('a'+(s[i]-'a'+key)%26); 
} 
} 
cout<<"Ciphertext is : "; 
cout<<s<<endl<<endl; 
break; 
case 2: 
cout<<"enter Ciphertext : " ; 
cin>>s1; 
int key2; 
cout<<"enter key : "; 
cin>>key2; 
key2=-key2; 
for(int i=0;i<s1.length();i++){ 
if(s1[i]>64&&s1[i]<91){ 
s1[i]=('Z'-('Z'-s1[i]-key2)%26); 
} 
if(s1[i]>96&&s1[i]<123){ 
s1[i]=('z'-('z'-s1[i]-key2)%26); 
} 
} 
cout<<"Plaintext is : "; 
cout<<s1<<endl<<endl; 
break; 
case 3: 
exit(1); 
} 
} 
}
