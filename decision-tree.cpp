#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Node{
    string label;
    int end;
    Node *left;//yes
    Node *right;//no

    Node(string l): label(l), end(0), left(nullptr), right(nullptr){}
}; 

void read_train(void);
void find_para(int lim);
vector<string> read_test(void);
Node* create_node(Node* r);
void run_tree(int n);

vector<string> _csv(string s);
string line;  
map<int, int> zero;
map<int, int> one;
map<int, int> two;
map<int, int> three;
map<int, int> four;
map<int, int> five;
map<int, int> six;
map<int, int> seven;
map<int, int> eight;
map<int, int> nine;
vector<int> f0, f1, f2, f3, f4, f5, f6, f7, f8, f9;
vector<string> now_pic;
Node* now ;
int cnt;

int main()
{
    //open train file
    ifstream inFile("mnist_train.csv", ios::in);
    if (!inFile)
    {
        cout << "開啟檔案失敗！" << endl;
        exit(1);
    } 

    //initialize map
    for(int i = 0; i < 781; ++i){
        zero[i] = 0;
        one[i] = 0;
        two[i] = 0;
        three[i] = 0;
        four[i] = 0;
        five[i] = 0;
        six[i] = 0;
        seven[i] = 0;
        eight[i] = 0;
        nine[i] = 0;
    }
    //read train data
    while (getline(inFile, line))
    { 
        read_train();
    }

    find_para(5500);
    //bulid a tree
    Node* root = new Node("-1");
    root = create_node(root);
    //open test file
    ifstream inFilet("mnist_test.csv", ios::in);
    if (!inFilet)
    {
        cout << "開啟檔案失敗！" << endl;
        exit(1);
    }  
    
    while (getline(inFilet, line))
    { 
        now_pic = read_test();
        now = root;
        now->label = "1";
        run_tree(1);
        
        if(now->end == 0){
            now->label = "0";
            run_tree(0);
            if(now->end == 0){
                now->label = "2";
                run_tree(2);
                if(now->end == 0){
                    now->label = "3";
                    run_tree(3);
                    if(now->end == 0){
                        now->label = "4";
                        run_tree(4);
                        if(now->end == 0){
                            now->label = "5";
                            run_tree(5);
                            if(now->end == 0){
                                now->label = "6";
                                run_tree(6);
                                if(now->end == 0){
                                    now->label = "7";
                                    run_tree(7);
                                    if(now->end == 0){
                                        now->label = "8";
                                        run_tree(8);
                                        if(now->end == 0){
                                            now->label = "9";
                                            run_tree(9);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        if(now_pic[780] == now->label){
            cout << now_pic[780] << " true" << endl;
        }
        else{
            cout << now_pic[780] << endl;
        }
        
    }
    
    return 0;
}
vector<string> _csv(string s)
{
    vector<string> arr;
    istringstream delim(s);
    string token;
    while (getline(delim, token, ','))        
    {
        arr.push_back(token);                                                      
    }
    return  arr;
}
void read_train(void)
{
    int j = 0;
    vector<string> a = _csv(line);

    j = a.size() - 1;
    if(a[j] == "0"){
        zero[j] = stoi(a[j]);
        j = 0;
        while(j < 780){
            if(a[j] != "0"){
                zero[j] += 1;
            }
            ++j;
        }
    }
    else if(a[j] == "1"){
        one[j] = stoi(a[j]);
        j = 0;
        while(j < 780){
            if(a[j] != "0"){
                one[j] += 1;
            }
            ++j;
        }
    }
    else if(a[j] == "2"){
        two[j] = stoi(a[j]);
        j = 0;
        while(j < 780){
            if(a[j] != "0"){
                two[j] += 1;
            }
            ++j;
        }
    }
    else if(a[j] == "3"){
        three[j] = stoi(a[j]);
        j = 0;
        while(j < 780){
            if(a[j] != "0"){
                three[j] += 1;
            }
            ++j;
        }
    }
    else if(a[j] == "4"){
        four[j] = stoi(a[j]);
        j = 0;
        while(j < 780){
            if(a[j] != "0"){
                four[j] += 1;
            }
            ++j;
        }
    }
    else if(a[j] == "5"){
        five[j] = stoi(a[j]);
        j = 0;
        while(j < 780){
            if(a[j] != "0"){
                five[j] += 1;
            }
            ++j;
        }
    }
    else if(a[j] == "6"){
        six[j] = stoi(a[j]);
        j = 0;
        while(j < 780){
            if(a[j] != "0"){
                six[j] += 1;
            }
            ++j;
        }
    }
    else if(a[j] == "7"){
        seven[j] = stoi(a[j]);
        j = 0;
        while(j < 780){
            if(a[j] != "0"){
                seven[j] += 1;
            }
            ++j;
        }
    }
    else if(a[j] == "8"){
        eight[j] = stoi(a[j]);
        j = 0;
        while(j < 780){
            if(a[j] != "0"){
                eight[j] += 1;
            }
            ++j;
        }
    }
    else if(a[j] == "9"){
        nine[j] = stoi(a[j]);
        j = 0;
        while(j < 780){
            if(a[j] != "0"){
                nine[j] += 1;
            }
            ++j;
        }
    }
}
void find_para(int lim)
{
    for(int x = 0; x < 780; ++x){
        if(zero[x] > lim){
            f0.push_back(x);
            cout << x << " zero: " << zero[x] << endl;
        }
        if(one[x] > 6000){
            f1.push_back(x);
            cout << x << " one: " << one[x] << endl;
        }
        if(two[x] > lim){
            f2.push_back(x);
            cout << x << " two: " << two[x] << endl;
        }
        if(three[x] > lim){
            f3.push_back(x);
            cout << x << " three: " << three[x] << endl;
        }
        if(four[x] > lim){
            f4.push_back(x);
            cout << x << " four: " << four[x] << endl;
        }
        if(five[x] > lim){
            f5.push_back(x);
            cout << x << " five: " << five[x] << endl;
        }
        if(six[x] > lim){
            f6.push_back(x);
            cout << x << " six: " << six[x] << endl;
        }
        if(seven[x] > lim){
            f7.push_back(x);
            cout << x << " seven: " << seven[x] << endl;
        }
        if(eight[x] > lim){
            f8.push_back(x);
            cout << x << " eight: " << eight[x] << endl;
        }
        if(nine[x] > lim){
            f9.push_back(x);
            cout << x << " nine: " << nine[x] << endl;
        }
        
        cout << endl;
    }
}
vector<string> read_test(void)
{
    vector<string> b = _csv(line);
    return b;
}
Node* create_node(Node* r)
{
    Node* newNode = new Node("1");
    r->left = nullptr;
    r->right = newNode;
    
    return r;
}
void run_tree(int n)
{
    vector<int> feature;
    if(n == 0){
        feature = f0;
    }
    else if(n == 1){
        feature = f1;
    }
    else if(n == 2){
        feature = f2;
    }
    else if(n == 3){
        feature = f3;
    }
    else if(n == 4){
        feature = f4;
    }
    else if(n == 5){
        feature = f5;
    }
    else if(n == 6){
        feature = f6;
    }
    else if(n == 7){
        feature = f7;
    }
    else if(n == 8){
        feature = f8;
    }
    else if(n == 9){
        feature = f9;
    }
    cnt = 0;
    for(int i = 0; i < feature.size(); ++i){
        if(now_pic[feature[i]] != "0"){
            ++cnt;
        }
    }
    if(cnt > feature.size()*0.8){
        now = now->left;
        now->end = 1;
    }
    else{
        now = now->right;
    }
}