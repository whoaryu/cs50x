#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    char *inputName = argv[1];
    FILE *input = fopen(inputName, "r");
    if (input == NULL)
    {
        printf("Could not open the file %s.\n", inputName);
        return 1;
    }
    BYTE block[BLOCK_SIZE];
    bool probablyJPEG = false;
    int outputNumber = 0;
    FILE *output = NULL;
    bool outputIsOpen = false;
    while (fread(block, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        bool emptyBlock = true;
        for (int i = 0; i < BLOCK_SIZE; i++)
        {
            if (block[i] != 0)
            {
                emptyBlock = false;
                break;
            }
        }
        if (emptyBlock && outputNumber > 0)
        {
            fclose(output);
            outputIsOpen = false;
            break;
        }
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && block[3] >= 0xe0)
        {
            if (outputNumber > 0)
            {
                fclose(output);
            }

            probablyJPEG = true;

            char outputName[8];
            sprintf(outputName, "%03i.jpg", outputNumber);
            output = fopen(outputName, "w");
            if (output == NULL)
            {
                printf("Could not create the file %s.\n", outputName);
                return 1;
            }
            outputIsOpen = true;
            outputNumber++;
        }
        if (probablyJPEG)
        {
            fwrite(block, 1, BLOCK_SIZE, output);
        }
    }
    if (outputIsOpen)
    {
        fclose(output);
    }
    fclose(input);
    return 0;
}