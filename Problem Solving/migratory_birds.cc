using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {
    unordered_map<int, int> sum_type;
    int index_lower = arr[0];
    int times_seen = 1;
    sum_type[arr[0]] = 1;
    for(int i = 1; i < arr.size(); ++i){
        //check if key exists
        if(sum_type.find(arr[i]) != sum_type.end()){
            sum_type[arr[i]] += 1;
            if(times_seen <= sum_type[arr[i]]){
                times_seen = sum_type[arr[i]];
                if( times_seen == sum_type[index_lower]){
                    index_lower = arr[i] < index_lower ? arr[i] : index_lower;
                } else {
                    index_lower = arr[i];
                }
            }
        } else {
            sum_type[arr[i]] = 1;
        }
    }
    return index_lower;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

