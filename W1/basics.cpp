#include <iostream>
#include <vector>

using namespace std;

void show_vector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    int a = 3;
    float b = 3.5;
    int x = 0;
    float y = 0.0;
    string txt = "Hello, ";

    cout << "Hello World!" << x << "." << y << txt << endl;

    string empty;
    string txt2 = txt + "World";
    cout << txt2 << endl;

    txt2[5] = '?';
    cout << txt2 << endl;

    txt2 = empty;
    cout << txt2 << endl;

    string option = "first";
    if (option == "first") {
        cout << option;
    }

    vector<int> vec = {1, 2, 3, 4};
    cout << vec.size() << endl;

    show_vector(vec);
    vec.push_back(5);
    show_vector(vec);
    vec.resize(3);
    show_vector(vec);

    vec[1] = 10;
    show_vector(vec);

    vector<int> copy = vec;
    show_vector(copy);

    vector<int> empty_vec;
    vec = empty_vec;
    show_vector(vec);

	cout << "----------" << endl;
	

    return 0;
}
