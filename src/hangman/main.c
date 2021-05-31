#include "libhangman/hangman.h"
#include <ctype.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int exit_condition = PLAY;
    int num_error;
    srand(time(NULL));

    while (exit_condition) {
        int value_dic;
        char** dic_name = open_dir(&value_dic, &num_error, "../dictionary");
        if (check_error(num_error) != WITHOUTERROR) {
            return num_error;
        }

        system("clear");
        print_theme_menu(dic_name, value_dic);
        printf("Please, choose theme for your game:\n");
        int theme;
        while ((theme = choose_theme(value_dic)) == INCORTHEME) {
            system("clear");
            print_theme_menu(dic_name, value_dic);
            printf("It isn't correct punct of menu. Try again.\n");
            continue;
        }

        char* path = concat_path_name(dic_name[theme - 1], &num_error);
        free_mem_arr(dic_name, value_dic);

        if (check_error(num_error) != WITHOUTERROR) {
            return num_error;
        }

        int value_words;
        char** words = get_words_array(&value_words, path, &num_error);
        free(path);
        if (check_error(num_error) != WITHOUTERROR) {
            return num_error;
        }

        int word_number = get_rand(0, value_words);
        size_t length = strlen(words[word_number]) - 1;

        char guessed_word[length];
        char hidden_word[length];
        char underline[] = "_";

        fill_arr(guessed_word, length, words[word_number]);
        fill_arr(hidden_word, length, underline);
        free_mem_arr(words, value_words);

        play_game(guessed_word, hidden_word, length);

        printf("\nDo you want to play again? Y/N\n");
        while ((exit_condition = play_again()) == INCORRECT) {
            system("clear");
            printf("\nDo you want to play again? Y/N\n");
            printf("\nIncorrect answer, please try again.\n");
            continue;
        }
        if (exit_condition == EXIT) {
            printf("\nThank you. Good bye!\n");
        }
    }
    return 0;
}
