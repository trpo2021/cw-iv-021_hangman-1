#pragma once

enum {
    CANTOPENDIR = -1,
    CANTOPENFILE = -2,
    CANTREALLOCMEM = -3,
    CANTCALLOCMEM = -4,
    CANTMALLOCMEM = -5,
    WITHOUTERROR = 0
};

enum { INCORLETTER = '0', INCORRECTLETTER = -1, CORRECTLETTER = 0 };

enum { INCORRECT = -2, PLAY = 1, EXIT = 0 };

enum { WITHPOINT = -1, WITHOUTPOINT = 0 };

enum { USEDLETTER = -1, UNUSEDLETTER = 0 };

enum { MAXERROR = 9, WIN = 1, LOSE = 2 };

enum { MAXLENGTH = 255, INITIALSIZE = 200, ALPHABETSIZE = 26 };

enum { INCORTHEME = -1 };

void print_hangman(int n);

void cut_ext(char* fname);

void print_theme_menu(char** dic_name, int value_dic);

int check_theme(char* arr, int value_dic);

void free_mem_arr(char** array, int value);

int choose_theme(int value_dic);

int get_rand(int min, int max);

void fill_arr(char* empty, int length, char* symbols);

int skip_point(char* name);

int cut_name(char* name, char** dic_name, int count_dic);

char** open_dir(int* value_dic, int* num_error, char* path);

char** get_words_array(int* value_words, char path[], int* num_error);

char* concat_path_name(char* dic_name, int* num_error);

int check_usage(char* used_ch, int max, char letter);

int check_letter(char choice[]);

char enter_letter(char* used_ch, int max);

int check_match(
        char* guessed, char* hidden, int len, char letter, int* num_guess_ch);

int play_game(char guessed_word[], char hidden_word[], int length);

int play_again();

int check_error(int error);
