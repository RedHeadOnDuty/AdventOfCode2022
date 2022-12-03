#include "../HelperClass.h"

///.1
// A/X Rock     ->  1
// B/Y Paper    ->  2
// C/Z Scissors ->  3
// Win      ->  6
// Draw     ->  3
// Loos     ->  0

///.2
// A Rock     ->  1
// B Paper    ->  2
// C Scissors ->  3
// X Loos     ->  0
// Y Draw     ->  3
// Z Win      ->  6

enum class EVictory_score{
    Loss = 0,
    Draw = 3,
    Win = 6
};

inline void Day2(){
    auto file = HelperClass::get_basic_ifstream(R"(Day2/SourceDay2.txt)");

    char his_hand, your_hand;
    int total_score = 0;
    int total_score_2 = 0;
    while (file >> his_hand >> your_hand){
        your_hand -= 23; // 'X' - 'A' = 23
        int difference_hand = his_hand - your_hand;

#define get_score(score_type) HelperClass::as_integer(score_type)
        switch (difference_hand) {
            case (-1):
            case (2):
                total_score += get_score(EVictory_score::Win);
                break;
            case (0):
                total_score += get_score(EVictory_score::Draw);
                break;
            default:
                return;
        }

        switch (your_hand) {
            case 'X':

            case 'Y':
                total_score += get_score(EVictory_score::Draw);
                break;
            case 'Z':
                total_score += get_score(EVictory_score::Win);
                break;
            default:
                return;
        }
#undef get_score

        std::printf("Difference %d, Your Hand = %d \n", difference_hand, your_hand - 'A' + 1);
        total_score += your_hand - 'A' + 1;
    }



    std::cout << "Total Score = " << total_score << std::endl;
    std::cout << "Day2 Finished!" << std::endl;
}
