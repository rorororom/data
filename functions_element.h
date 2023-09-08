const int MAX_SIZE = 100;

// void print_element_rectangular (int* data, size_t row, size_t cols);
void print_element_triangular (const int* data, const size_t row, const size_t cols);
// void get_element_rectangular (const char* data, size_t row, size_t cols, size_t i, size_t j);
int get_element_triangular (const int const* data, const size_t row, const size_t cols, const size_t i, const size_t j);
// char* set_element_rectangular (int* data, size_t row, size_t cols, size_t i, size_t j, int replace);
int* set_element_triangular (int* data, const size_t row, const size_t cols, int &i, int &j, const int replace);
// void address_element_rectangular (int* data, size_t row, size_t cols, size_t i, size_t j);
// void goal_recording (int* data, size_t row, size_t cols, size_t i, size_t j, int goals);
// void s_validation (int *first_team, int *second_team);
void input_validation (int& first_team, int& second_team, int& goals);
void input_user (int* data, const size_t row, const size_t cols);
