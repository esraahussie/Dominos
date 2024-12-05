
// Structure to represent a domino piece
struct dominoT {
    int leftDots;
    int rightDots;
};

// Recursive function to check if it's possible to form a domino chain
bool FormsDominoChain(vector<dominoT>& dominos, vector<bool>& visited, ll currentIndex, int count, vector<dominoT>& resdominos) {
    if (count == dominos.size()) return true;
    visited[currentIndex] = true;
    resdominos.push_back(dominos[currentIndex]);

    for (int i = 0; i < dominos.size(); i++) {
        if (!visited[i]) {
            if (dominos[currentIndex].rightDots == dominos[i].leftDots) {
                if (FormsDominoChain(dominos, visited, i, count + 1, resdominos)) {
                    return true;
                }
            }
            else if (dominos[currentIndex].rightDots == dominos[i].rightDots) {
                swap(dominos[i].leftDots, dominos[i].rightDots);
                if (FormsDominoChain(dominos, visited, i, count + 1, resdominos)) {
                    return true;
                }
                swap(dominos[i].leftDots, dominos[i].rightDots);
            }
        }
    }

    visited[currentIndex] = false;
    resdominos.pop_back();
    return false;
}

// Function to print the dominos in the correct format
void printDomino(vector<dominoT>& resdominos) {
    for (int i = 0; i < resdominos.size(); i++) {
        cout << resdominos[i].leftDots << "|" << resdominos[i].rightDots;
        if (i != resdominos.size() - 1) cout << " - ";
    }
    cout << endl;
}


void Domino(){
    ll numDominos;
    cout << "Enter the number of dominos: ";
    cin >> numDominos;

    vector<dominoT> dominos(numDominos);
    vector<bool> visited(numDominos, false);

    for (int i = 0; i < numDominos; i++) {
        cout << "Enter the domino " << i + 1 << " with space between two numbers: ";
        cin >> dominos[i].leftDots >> dominos[i].rightDots;
        cout << "\n";
    }

    vector<dominoT> resdominos;
    bool canFormChain = false;
    for (int i = 0; i < numDominos; i++) {
        if (FormsDominoChain(dominos, visited, i, 1, resdominos)) {
            canFormChain = true;
            break;
        }
    }

    if (canFormChain) {
        cout << "It is possible to form a domino chain. The chain is: " << endl;
        printDomino(resdominos);
    }
    else {
        cout << "It is not possible to form a domino chain with the given pieces." << endl;
    }
}
int main(){
    while(true){
        cout<<"Welcome in my program ! \n";
        cout<<"A) start your program \n"<<"B) End !\n";   cout<<" Enter your choice : ";
        char ch;
        cin>>ch;
        if (ch=='A') {
              Domino();
        }
        else if(ch=='B'){
              cout<<"Thanks for using my program !";
             break;
        }
    }
}