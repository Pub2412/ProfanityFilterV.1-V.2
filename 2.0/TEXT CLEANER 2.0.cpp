#include <iostream>
#include <cstring>
#include <cctype>

const int MAX_INPUT_SIZE = 300;
const int MAX_BAD_WORDS = 500;
const int MAX_WORD_SIZE = 500;

// Function to convert a string to lowercase
void toLowerCase(const char* source, char* dest) {
    for (int i = 0; source[i]; ++i) {
        dest[i] = std::tolower(source[i]);
    }
    dest[strlen(source)] = '\0'; // Null-terminate the destination string
}

// Function to filter bad words from the input string and count them
int filterBadWords(char input[], const char badWords[][MAX_WORD_SIZE], const char niceWords[][MAX_WORD_SIZE], int badWordCount) {
    char lowerInput[MAX_INPUT_SIZE];
    toLowerCase(input, lowerInput); // Convert input to lowercase

    char filtered[MAX_INPUT_SIZE];
    strcpy(filtered, input); // Start with the original input

    int badWordCountTotal = 0; // Counter for bad words

    for (int i = 0; i < badWordCount; ++i) {
        char lowerBadWord[MAX_WORD_SIZE];
        toLowerCase(badWords[i], lowerBadWord); // Convert bad word to lowercase

        char* pos = strstr(lowerInput, lowerBadWord);
        while (pos != nullptr) {
            // Increment bad word counter
            badWordCountTotal++;

            // Get the position of the found bad word
            size_t index = pos - lowerInput;

            // Create a new filtered string
            char temp[MAX_INPUT_SIZE];
            strncpy(temp, filtered, index); // Copy up to the bad word
            temp[index] = '\0'; // Null-terminate the temporary string

            // Concatenate the nice word
            strcat(temp, niceWords[i]); // Add the nice word
            strcat(temp, pos + strlen(badWords[i])); // Add the rest of the original string

            // Copy the updated filtered string back
            strcpy(filtered, temp);

            // Look for the next occurrence
            lowerInput[index] = '\0'; // Null-terminate to prevent further searches in the replaced part
            toLowerCase(filtered, lowerInput); // Reconvert to lowercase for next search
            pos = strstr(lowerInput, lowerBadWord);
        }
    }

    // Copy the filtered result back to input
    strcpy(input, filtered);

    return badWordCountTotal; // Return the total count of bad words
}

int main() {
    char input[MAX_INPUT_SIZE];
    char badWords[MAX_BAD_WORDS][MAX_WORD_SIZE] = {
        "puta", 
		"bobo", 
		"tanga", 
		"bugo", 
		"pakshet", 
		"shit", 
		"punyeta", 
		"putang", 
		"pakyu", 
		"fuck you", 
		"fuck", 
		"burikat", 
		"kigol", 
		"iyot", 
		"pipi", 
		"bisong", 
		"bilat", 
		"puki", 
		"pekpek",
		"tintin", 
		"titi", 
		"otin", 
		"burat", 
		"hayup", 
		"hayup ka", 
		"letse", 
		"bushet", 
		"putangina", 
		"yawa", 
		"ulol", 
		"lintik", 
		"walang hiya",
		"gago",
		"bitch",
		"putik",
		"pota", // Customize your bad words here
    };
    char niceWords[MAX_BAD_WORDS][MAX_WORD_SIZE] = {
        "I love you",
		"Pogi!",
		"Cutie",
		"I love you",
		"Pogi!",
		"Cutie",
		"I love you",
		"Pogi!",
		"Cutie",
		"I love you",
		"Pogi!",
		"Cutie",
		"I love you",
		"Pogi!",
		"Cutie",
		"I love you",
		"Pogi!",
		"Cutie",
		"I love you",
		"Pogi!",
		"Cutie",
		"I love you",
		"Pogi!",
		"Cutie",
		"I love you",
		"Pogi!",
		"I love you",
		"Pogi!",
		"Cutie",
		"Cute",
		"Ganda",		
		"Cutie",
		"Pogi!",
		"Ganda",
		"Ganda",
		"Pantastik!",
		"Brooo",
 // Corresponding nice words
    };
    int badWordCount = 36; // Number of bad words

     std::cout << R"(
    _____  ____  _______     ___   __    __  _        __  __  
   /__   \/__\ \/ /__   \   / __\ / /   /__\/_\    /\ \ \/__\/__\ 
     / /\/_\  \  /  / /\/  / /   / /   /_\ //_\\  /  \/ /_\ / \// 
    / / //__  /  \ / /    / /___/ /___//__/  _  \/ /\  //__/ _  \ 
    \/  \__/ /_/\_\\/     \____/\____/\__/\_/ \_/\_\ \/\__/\/ \_/
                 	Make your words clean!
                   
	)" << '\n';
	
    std::cout << "\t Enter your message: ";
    std::cin.getline(input, MAX_INPUT_SIZE);
    
     system("cls");

    int count = filterBadWords(input, badWords, niceWords, badWordCount);
    
         std::cout << R"(
    _____  ____  _______     ___   __    __  _        __  __  
   /__   \/__\ \/ /__   \   / __\ / /   /__\/_\    /\ \ \/__\/__\ 
     / /\/_\  \  /  / /\/  / /   / /   /_\ //_\\  /  \/ /_\ / \// 
    / / //__  /  \ / /    / /___/ /___//__/  _  \/ /\  //__/ _  \ 
    \/  \__/ /_/\_\\/     \____/\____/\__/\_/ \_/\_\ \/\__/\/ \_/
                 	Make your words clean!
                   
	)" << '\n';

    std::cout << "\t Filtered Message: " << input << std::endl;
    std::cout << "\t Number of bad words replaced: " << count << std::endl;

    return 0;
}
