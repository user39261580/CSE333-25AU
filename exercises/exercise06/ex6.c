#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int is_input_valid(int argc, char const *argv[]);
int is_file_valid(FILE* file);

int main(int argc, char const *argv[]) {
  if (!is_input_valid(argc, argv)) {
    return EXIT_FAILURE;
  }
  const char* file_name = argv[1];
  FILE* file = fopen(file_name, "rb");
  if (!is_file_valid(file)) {
    return EXIT_FAILURE;
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  
  // Read character by character from the end of file
  for (long i = file_size - 1; i >= 0; i--) {
    // Seek to position i
    if (fseek(file, i, SEEK_SET)) {
      perror("fseek");
      fclose(file);
      return EXIT_FAILURE;
    }
    
    // Read one character
    char ch;
    size_t bytes_read = fread(&ch, sizeof(char), 1, file);
    
    printf("%c", ch);
  }
  
  fclose(file);
  return EXIT_SUCCESS;
}

int is_input_valid(int argc, char const *argv[]) {
  // Check whether args count is correct
  if (argc != 2) {
    printf("Invalid input\n");
    return 0;
  }

  return 1;
}

int is_file_valid(FILE* file) {
  if (file == NULL) {
    perror("fopen");
    return 0;
  }

  if (fseek(file, 0, SEEK_END) != 0) {
    perror("fseek");
    fclose(file);
    return 0;
  }

  long file_size = ftell(file);
  if (file_size < 0) {
    perror("ftell");
    fclose(file);
        return 0;
  }

  return 1;
}