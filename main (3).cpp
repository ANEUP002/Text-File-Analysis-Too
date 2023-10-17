#include <iostream>
#include<fstream>
#include<string>
#include<ctype.h>
#include<vector>
#include<cctype>
#include<algorithm>
#include <bits/stdc++.h>
#include <iterator>


using namespace std;

vector<string> read_file(string fileName){

  string line;
  ifstream myfile ;
  string word ;

  vector <string> word_from_file;

  
  myfile.open(fileName);


  while (!myfile.is_open()){
   
    cout <<"Invalid file Name. Please re-enter: ";
    getline(cin, fileName);
    myfile.open(fileName);
  }

    while (getline(myfile,line)){

    for (int i = 0; i<(line.length()+1); i++){


        if (isalpha(line[i])){
            word +=toupper(line[i]);
            }
        else{
            if (word !=""){
                word_from_file.push_back(word);
                }

            word="";
            }

        }
    }


    cout<<"The contents of the files are: "<<endl;
    for (auto it = word_from_file.begin(); it != word_from_file.end(); it++)
        cout << *it << " "<<endl;



    myfile.close();
    return word_from_file;


}

vector<string> sort_vector(vector<string> vector_name){
    sort(vector_name.begin(), vector_name.end());
    for (int i =0; i<vector_name.size();i++){
        cout<< vector_name[i]<<" "<<endl;
    }
    return vector_name;
}

vector<int> count_vector(vector<string> vector_name){
    vector<string> unique_vector;
    vector<int> counter_vector;
    unique_vector = vector_name;
    unique_vector.erase(unique(unique_vector.begin(), unique_vector.end()), unique_vector.end());
    for (int i=0; i<unique_vector.size(); i++){
        counter_vector.push_back(0);
    }

    for (auto& i: vector_name){
        for(int j =0; j<unique_vector.size(); j++){
            if (i == unique_vector[j]){
                counter_vector[j]+=1;
                break;
            }
        }

    }

    for (int i=0; i<unique_vector.size(); i++){
        cout<< unique_vector[i]<< " is repeated "<< counter_vector[i]<< " times. "<<endl;
    }

    return counter_vector;
}






int main () {
  string command;
  string word;
  vector<string> final;
  vector<int> counter_vect;


  cout<<"Enter Command: ";
  getline(cin, command);


  while(command != "exit"){


  vector<string> files ={};

  for (int i = 0; i<(command.length()+1); i++){


    if (files.size() ==0){
        if (isalpha(command[i])){
            word +=toupper(command[i]);
        }
        else{
         

        files.push_back(word) ;

        word="";
    }
  }
   else{
      
      word+=command[i];
    }
  }


    files.push_back(word);
    word="";

     if (files[0]=="READ"){
   
        final =read_file(files[1]);
        }
     if (files[0] =="SORT"){
      
        final=sort_vector(final);
        }
    if (files[0] == "COUNT"){

        counter_vect = count_vector(final);
    }
   



  cout<<"Enter Command again: ";
  getline(cin, command);
  }


  exit(0);

  return 0;
}


