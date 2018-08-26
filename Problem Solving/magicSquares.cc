#include <iostream>
#include <vector>
using namespace std;

/**
 * Return true if given 3*3 square is a magic square.
 */
bool isMagicSquare(vector<int> &magicSquare){
    // 3*3 magic square just have one magic number, 15.
    int magicNumber = 15;
    // check rows
    for(int i = 0; i < 3; ++i){
        int sumRow = 0;
        for(int j = 0; j < 3; ++j){
            sumRow += magicSquare[i*3+j];
        }
        if (sumRow != 15){
            return false;
        }
    }
    
    // check columns
    for(int j = 0; j < 3; ++j){
        int sumColumn = 0;
        for(int i = 0; i < 3; ++i){
            sumColumn += magicSquare[i*3+j];
        }
        if (sumColumn != 15){
            return false;
        }
    }
    // check diagonals
    if(15 != (magicSquare[0] + magicSquare[4] + magicSquare[8])){
        return false;
    }
    if(15 != (magicSquare[6] + magicSquare[4] + magicSquare[2])){
        return false;
    }
    return true;
}

/**
 * Get all 3*3 magic squares
 */
vector<vector<int> > getMagicSquares(){
    vector<vector<int> > magicSquares;
    vector<int> singleMagicSquare(9);
    for(int i = 0; i < 9; ++i){
        singleMagicSquare[i] = i+1;
    }
    while(std::next_permutation(singleMagicSquare.begin(), singleMagicSquare.end())){
        if(isMagicSquare(singleMagicSquare)){
            magicSquares.push_back(singleMagicSquare);
        }
    }
    
    return magicSquares;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int> > s) {
    vector<vector<int> > magicSquares = getMagicSquares();
    int minDif = -1;
    for(int i = 0; i < magicSquares.size(); ++i){
        //check difference with each magicSquare already found
        int dif = 0;
        vector<int> currentMagicSquare = magicSquares[i];
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
                dif += std::abs(s[j][k] - currentMagicSquare[j*3+k]);
            }
        }
        if(minDif == -1 || minDif > dif){
            minDif = dif;
        }
    }
    return minDif;
}

int main()
{

    vector<vector<int> > s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

    }

    int result = formingMagicSquare(s);

    cout << result << "\n";


    return 0;
}