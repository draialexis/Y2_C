//
// Created by draia on 13/10/2021.
//

#ifndef Y2_C_TP2EX5_H
#define Y2_C_TP2EX5_H

#define BFR 512

char *permuteString(char *str, int *arr)
{
    // TODO more user input validation? seems rough in C, esp. given the _cahier des charges_

    if (strlen(str) > 0 && str != NULL && arr != NULL)
    {
        char *res = malloc(sizeof(char) * strlen(str));
        if (res == NULL)
        {
            MALLOC_FAIL
        }

        sprintf(res, "%s", str); //initializing the string

        for (int i = 0; i < strlen(str); i++)
        {
            res[arr[i]] = str[i];
            printf("res[%d] = %c / str[%d] = %c\n", arr[i], res[arr[i]], i, str[i]);
        }
        return res;
    }
    else
    {
        EMPTY_OR_NULL
        return NULL;
    }
}

void encode(char *txt_f_name, char *perm_f_name)
{
    FILE *fp_txt = fopen(txt_f_name, "r");
    checkFopen(fp_txt);
    FILE *fp_perm = fopen(perm_f_name, "r");
    checkFopen(fp_perm);

    int c;
    char *txt = (char *)malloc(sizeof(char) * BFR);
    sprintf(txt, "%c", '\0');
    int *perm = (int *)malloc(sizeof(int) * BFR);

    if (txt == NULL || perm == NULL)
    {
        MALLOC_FAIL
    }

    while (1)
    {
        c = fgetc(fp_txt);
        if (feof(fp_txt))
        {
            break;
        }
        sprintf(txt + strlen(txt), "%c", c);
    }

    char *txt_perm = (char *)malloc(sizeof(char) * BFR);
    sprintf(txt_perm, "%c", '\0');

    int n = 0;
    while (1)
    {
        c = fgetc(fp_perm);
        if (feof(fp_perm))
        {
            break;
        }
        // vomitting face emoji
        sprintf(txt_perm, "%c", c);
        perm[n] = atoi(txt_perm);
        n++;
    }

    // printing file contents, debugging
    /*
    printf("%s\n", txt);

    if (n > 0 && Perm != NULL)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            printf("%d", Perm[i]);
            if (i < n - 1)
            {
                printf(",");
            }
            else
            {
                printf("\n");
            }
        }
    }
    else
    {
        EMPTY_OR_NULL
    }
    */

    fclose(fp_txt);
    fclose(fp_perm);

    fp_txt = fopen(txt_f_name, "w");
    fp_perm = fopen(perm_f_name, "w");

    for (int i = 0; i < strlen(txt) / n; i++)
    {

    }

    fclose(fp_txt);
    fclose(fp_perm);
}
#endif //Y2_C_TP2EX5_H
