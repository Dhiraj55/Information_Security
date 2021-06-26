#include<bits/stdc++.h>
using namespace std;
map<int,int> keyMap;
string key;
void setPermutationOrder(string key)
{             
    for(int i=0; i < key.length(); i++)
    {
        keyMap[key[i]] = i;
    }
}
string encryptMessage(string msg)
{
	int row,col,j;
	string cipher = "";
	col = key.length();
	row = msg.length()/col;
	
	if (msg.length() % col)
		row += 1;

	char matrix[row][col];

	for (int i=0,k=0; i < row; i++)
	{
		for (int j=0; j<col; )
		{	
			if( isalpha(msg[k]))
			{
				matrix[i][j] = msg[k];
				j++;
			}
			k++;
		}
	}
	cout<<endl;
	for(int z=0;z<col;z++){
		cout<<key[z]<<" ";
	}
	cout<<endl;
	for (int i=0,k=0; i < row; i++)
	{
		for (int j=0; j<col; j++ )
		{
          cout << matrix[i][j] << " ";
		}
		cout<<endl;
	}	
   for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii)
    {
        j=ii->second;
        for (int i=0; i<row; i++)
        {
            if( isalpha(matrix[i][j]) || matrix[i][j]==' ' || matrix[i][j]=='_')
                cipher += matrix[i][j];
        }
    }
	return cipher;
}

string decryptMessage(string cipher,string key)
{
	int col = key.length();
	int row = cipher.length()/col;
	char cipherMat[row][col];
	for (int j=0,k=0; j<col; j++)
		for (int i=0; i<row; i++)
			cipherMat[i][j] = cipher[k++];
			
    char decCipher[row][col];
    map<int,int>::iterator ii=keyMap.begin();
    int k = 0;
    for (int l=0,j;l< key.length();l++)
    {
        j = key[l]-'0'-1;
        for (int i=0; i<row; i++)
        {
            decCipher[i][k]=cipherMat[i][j];
        }
        k++;
    }

    string msg = "";
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(decCipher[i][j] != '_')
                msg += decCipher[i][j];
        }
    }
    return msg;
}

int main(void)
{
	string msg;
	cout << "Enter plain text: ";
	getline(cin,msg);
	cout<<"Enter key : ";
	cin >> key;
 	setPermutationOrder(key);
	
	string cipher = encryptMessage(msg);
	cout << "Encrypted Message: " << cipher << endl;
	
    cout << "Decrypted Message: " << decryptMessage(cipher,key) << endl;

	return 0;
}

