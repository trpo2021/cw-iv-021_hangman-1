#include "ctest.h"
#include "libhangman/hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CTEST(Check_theme, Check_theme_work)
{
    char* choice[] = {"3", "k", "}", "5"};
    int exp[] = {3, INCORTHEME, INCORTHEME, INCORTHEME};
    int value_dic = 4;
    for (int i = 0; i < 4; i++) {
        int theme = check_theme(choice[i], value_dic);
        ASSERT_EQUAL(exp[i], theme);
    }
}

CTEST(Concat_path_name, Correct_path)
{
    int num_error;
    char* dir_name = "animals";
    char* path = concat_path_name(dir_name, &num_error);
    char* exp = "../dictionary/animals.txt";
    ASSERT_STR(exp, path);
    ASSERT_EQUAL(WITHOUTERROR, num_error);
}

CTEST(Check_letter, Check_letter_work)
{
    char* choice[] = {"i", "5", ";", "\n", "\t", " "};
    int real = check_letter(choice[0]);
    ASSERT_EQUAL(CORRECTLETTER, real);

    for (int i = 1; i < 6; i++) {
        int real = check_letter(choice[i]);
        ASSERT_EQUAL(INCORRECTLETTER, real);
    }
}

CTEST(Check_usage, Check_usage_work)
{
    char* used_ch = "abcd";
    char choice[] = {'a', 'i'};
    int exp[] = {USEDLETTER, UNUSEDLETTER};
    for (int i = 0; i < 2; i++) {
        int real = check_usage(used_ch, strlen(used_ch), choice[i]);
        ASSERT_EQUAL(exp[i], real);
    }
}

CTEST(Check_match, Check_match_work)
{
    char* word = "panda";
    size_t length = strlen(word) - 1;
    int num_guess_ch = length;
    char guessed_word[length];
    char hidden_word[length];
    char underline[] = "_";
    char letter[] = {'p', 'c'};

    fill_arr(guessed_word, length, word);
    fill_arr(hidden_word, length, underline);

    int no_match = check_match(
            guessed_word, hidden_word, length, letter[0], &num_guess_ch);
    ASSERT_NOT_EQUAL(length, no_match);
    no_match = check_match(
            guessed_word, hidden_word, length, letter[1], &num_guess_ch);
    ASSERT_EQUAL(length, no_match);
}

CTEST(Cut_ext, Cut_ext)
{
    char file_name[] = "trpo.txt";
    char exp[] = "trpo";
    cut_ext(file_name);
    ASSERT_STR(exp, file_name);
}

CTEST(Cut_name, Cut)
{
    char* d_name = "animals.txt";
    char exp[] = "animals";
    int count_dic = 0;
    char* dir_name[MAXLENGTH];
    int status = cut_name(d_name, dir_name, count_dic);
    ASSERT_EQUAL(WITHOUTERROR, status);
    ASSERT_STR(exp, dir_name[0]);
}

CTEST(Get_words_array, Get_words_array_work)
{
    int value_words;
    int num_error;
    char* path[] = {"../dictionary/animals.txt", "../dictionary/error.dat"};
    int exp[] = {WITHOUTERROR, CANTOPENFILE};

    for (int i = 0; i < 2; i++) {
        get_words_array(&value_words, path[i], &num_error);
        ASSERT_EQUAL(exp[i], num_error);
    }
}

CTEST(Skip_point, Skip_point_work)
{
    char* name[] = {".", "animals.txt"};
    int exp[] = {WITHPOINT, WITHOUTPOINT};
    for (int i = 0; i < 2; i++) {
        int real = skip_point(name[i]);
        ASSERT_EQUAL(exp[i], real);
    }
}

CTEST(Fill_arr, Fill)
{
    char* word = "mouse";
    size_t length = strlen(word);
    char guessed_word[length];
    char hidden_word[length];
    char underline[] = "_";

    fill_arr(guessed_word, length, word);
    fill_arr(hidden_word, length, underline);

    ASSERT_STR(guessed_word, word);

    char underline_mod[] = "_____";
    underline_mod[length] = '\0';

    ASSERT_STR(hidden_word, underline_mod);
}

CTEST(Open_dir, Open_dir_work)
{
    int value_dic, num_error;
    char* dir_path[] = {"../dictionary", "../dictionaaary"};
    int exp[] = {WITHOUTERROR, CANTOPENDIR};
    for (int i = 0; i < 2; i++) {
        open_dir(&value_dic, &num_error, dir_path[i]);
        ASSERT_EQUAL(exp[i], num_error);
    }
}
