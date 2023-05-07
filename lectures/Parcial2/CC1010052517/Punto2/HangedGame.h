#include <string>

using namespace std;

class Hang{
    public:
        Hang();

    private:
        string randomWord();
        bool checkFile();
        void CodifiedWord(string);

        void chooseHanged();

        void inputGuess();
        void FullGuess();

        void start();

        string word;
        string codifiedWord;
        string guessedLetters;
        string replay;
        short int lives;
        bool status;
};