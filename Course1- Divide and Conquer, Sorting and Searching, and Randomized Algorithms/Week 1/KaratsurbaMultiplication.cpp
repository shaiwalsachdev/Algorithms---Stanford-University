#include<bits/stdc++.h>
using namespace std;
#include <sstream>
#include <iostream>
#include <string>

string finddiff(string num1,string num2){
    ///  num1 - num2
    if (num1 == num2)
        return "0";
    int len1 = num1.length();
    int len2 = num2.length();
    int diff = len1 - len2;
    int carry = 0;
    string resofdiff = "";
    for(int i = len2 - 1;i >= 0; i--){
            int d = (num1[i+diff]-'0') - (num2[i]-'0') - carry;
            if(d>=0)
                carry = 0;
            else{
                d += 10;
                carry = 1;
            }
            char ch = d +'0';
            resofdiff = ch + resofdiff;
    }

    // Rest Digits
    for(int j = len1-len2-1;j >= 0; j--){
        if(carry == 1 && num1[j] == '0'){
            char ch = '9';
            resofdiff = ch + resofdiff;
            continue;
        }
        int d = (num1[j]-'0') - carry;
        if(j > 0 || d > 0){
            char ch1 = d +'0';
            resofdiff = ch1 + resofdiff;
        }
        carry = 0;
    }

    //Remove initial Zeros
    int c = 0;
    for(int i = 0;i < resofdiff.length();i++){
        if(resofdiff[i]-'0' > 0)
            break;
        else
            c++;
    }
    //cout << c << endl;
    resofdiff = resofdiff.substr(c);
    cout << "Diff" << " "<<num1 << " "<<num2 <<" "<<resofdiff<<endl;
    return resofdiff;
}


string findadd(string num1,string num2){
    ///  num1 - num2
    if (num1.length() < num2.length())
        swap(num1, num2);
    int len1 = num1.length();
    int len2 = num2.length();
    int diff = len1 - len2;
    int carry = 0;
    string resofadd = "";
    for(int i = len2 - 1;i >= 0; i--){
            int d = (num1[i+diff]-'0') + (num2[i]-'0') + carry;
            if(d<=9)
                carry = 0;
            else{
                d = d%10;
                carry = 1;
            }
            char ch = d +'0';
            resofadd = ch + resofadd;
    }

    // Rest Digits
    for(int j = len1-len2-1;j >= 0; j--){

        int d = (num1[j]-'0') + carry;
        if(d<=9)
            carry = 0;
        else{
            d = d%10;
            carry = 1;
        }
        char ch1 = d +'0';
        resofadd = ch1 + resofadd;


    }
    if(carry > 0){
        char ch1 = carry +'0';
        resofadd = ch1 + resofadd;
    }

    int c = 0;
    for(int i = 0;i < resofadd.length();i++){
        if(resofadd[i]-'0' > 0)
            break;
        else
            c++;
    }
    //cout << c << endl;
    resofadd = resofadd.substr(c);
    cout << "Sum"<<" "<<num1 << " "<<num2 <<" "<<resofadd<<endl;
    return resofadd;
}

string findproduct(string number1,string number2,int n){

string a = "";
string b = "";
string c = "";
string d = "";
int length = number1.length();

if (length == 1){
    int first = number1[0]-'0';
    int second = number2[0]-'0';
    int result = first*second;

    char lastdigit = ((result%10))+'0';
    result = result / 10;
    char secondlastdigit = ((result%10))+'0';
    string res = "";
    res = lastdigit + res;
    res = secondlastdigit + res;
    if (res[0] == '0'){
        res = "";
        res = res + lastdigit;
    }

    //cout << res << endl;
    return res;
}


if(length > 1){

int mid = (length-1)/2;

for(int i= 0;i <=mid;i++)
    a = a + number1[i];

for(int i= mid+1;i <length;i++)
    b = b + number1[i];

for(int i= 0;i <=mid;i++)
    c = c + number2[i];

for(int i= mid+1;i <length;i++)
    d = d + number2[i];


cout << "a = "<<a << endl;
cout << "b = " << b << endl;
cout << "c = " <<c << endl;
cout << "d = " <<d << endl;


int check = a.length() - c.length();
if(check != 0){
    for(int i = 1;i <= abs(check);i++){
        if(check > 0)
            c = '0' + c;
        else
            a = '0' + a;
    }
}

string product1 = findproduct(a,c,a.length());
cout <<  a <<" " << c<< "" <<" " <<product1 <<endl;


int check1 = b.length() - d.length();
if(check1 != 0){
    for(int i = 1;i <= abs(check1);i++){
        if(check1 > 0)
            d = '0' + d;
        else
            b = '0' + b;
    }
}

string product2 = findproduct(b,d,b.length());
cout <<  b <<" " << d<< "" <<" "<<product2<<endl;
string ab = findadd(a,b);
string cd = findadd(c,d);

int check2 = ab.length() - cd.length();
if(check2 != 0){
    for(int i = 1;i <= abs(check2);i++){
        if(check2 > 0)
            cd = '0' + cd;
        else
            ab = '0' + ab;
    }
}



string product3 = findproduct(ab,cd,ab.length());
cout <<  ab <<" " << cd<< "" <<" "<<product3 <<endl;
string findiff1 = finddiff(product3,product2);
cout << findiff1 << endl;
string findiff2 = finddiff(findiff1,product1);
cout << findiff2 << endl;
if(n%2 ==1){
for(int i = 1;i <= n-1; i++){
    product1 = product1 + '0';
}
}
else{
    for(int i = 1;i <= n; i++){
    product1 = product1 + '0';
}
}
for(int i = 1;i <= (n/2); i++){
    findiff2 = findiff2 + '0';
}

string result1 = findadd(product1,findiff2);

string finalresult = findadd(product2,result1);

return finalresult;

}

}


int main()
{
    string number1;
    string number2;
    cin >> number1 >> number2;

    //cout << finddiff(number1,number2) << endl
    int check2 = number1.length() - number2.length();
    if(check2 != 0){
        for(int i = 1;i <= abs(check2);i++){
            if(check2 > 0)
                number2 = '0' + number2;
            else
                number1 = '0' + number1;
        }
    }

    cout << findproduct(number1,number2,number1.length()) << endl;
    return 0;
}
