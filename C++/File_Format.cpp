#include<bits/stdc++.h>
using namespace std;


// Class for removing white spaces
class WhiteSpaceRemovingClass{

    public:
    void ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    }

    void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
    }

    void trim(string &s) {
    WhiteSpaceRemovingClass obj;
    obj.ltrim(s);
    obj.rtrim(s);
    }
};


//Class for object Storage
class ObjectStorageClass{
    public:
    string arr[9];

    //Parameterized constructor
    ObjectStorageClass(string data[]){
        for(int i=0;i<9;i++){
            arr[i]=data[i];
        }
    }
};




vector<string> readFileToVector(const string &filename)
{   
    //Initializing the file input variable
    ifstream file;

    // Reading the file 
    file.open(filename);

    // vector for storing lines
    vector<string> lines;

    string line;

    // Iterating to get lines from the source
    while (getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}


//Global Object Storage
vector<ObjectStorageClass> globalObj;


//Function to display vectorized strings
void FuncToDisplay(const vector<string> stringVec)
{   
    // Initializing the size of each entry
    int sizeVector[]={15,15,15,10,5,20,15,15,6};

    // Initializing a map for integer and string
    map<int, string> data;

    WhiteSpaceRemovingClass obj1;
    for (int i = 0; i <= stringVec.size(); i++)
        {   
            string c="";
            string l=stringVec[i]+c;
            string arr[9];
            int k=0;

            // Looping for adding extra spaces for empty fields
            for(int j=0;j<9;j++){
                arr[j]=l.substr(k,sizeVector[j]);
                k+=sizeVector[j];
                obj1.trim(arr[j]);

            }
            ObjectStorageClass objStorage(arr);
            globalObj.push_back(objStorage);
        }
        
}


// Function for Envelop Formatting
void EnvelopFormat(string arr[]){
        string name;
        string address1;
        string address2;
        if(arr[1][0]!='\0'){
            name=arr[1]+' '+arr[0]+" ";
        }
        else{
            name=arr[0] + " ";
        }
        if(arr[4][0]!='\0'){
            address1=arr[4]+' '+arr[5]+ " ";
        }
        else{
            address2=arr[5]+ " ";
        }
        int i=0;
        if(arr[6][0]!='\0'){
            address2=arr[6]+", "+arr[7];
            i+=2;
        }
        else{
            address2=arr[7];
        }
        if(address2[0]!='\0'){
            i+=1;
            address2+=" "+arr[8]+ " ";
            
        }
        else{
            address2+=arr[8]+" ";
        }
        cout<<name<<'\n';
        cout<<address1<<'\n';
        cout<<address2<<'\n';
    
}
       

int main(int argc,  char **argv)
{
    
    // Reading input from the command line
    string Filename = argv[2];

    //Initialzing a vector of type strings to store vectorized string
    vector<string> characters = readFileToVector(Filename);

    FuncToDisplay(characters);
    
    // Printng all the records
    for(int i=0; i<globalObj.size(); i++){

        EnvelopFormat(globalObj[i].arr);
    }
}