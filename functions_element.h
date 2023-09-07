

// void print_element_rectangular (int* data, size_t row, size_t cols);
void print_element_triangular (int* data, size_t row, size_t cols);
// void get_element_rectangular (const char* data, size_t row, size_t cols, size_t i, size_t j);
void get_element_triangular (int* data, size_t row, size_t cols, size_t i, size_t j);
// char* set_element_rectangular (int* data, size_t row, size_t cols, size_t i, size_t j, int replace);
int* set_element_triangular (int* data, size_t row, size_t cols, int i, int j, int replace);
// void address_element_rectangular (int* data, size_t row, size_t cols, size_t i, size_t j);
// void goal_recording (int* data, size_t row, size_t cols, size_t i, size_t j, int goals);
// void s_validation (int *first_team, int *second_team);
void checking_order (int& first_team, int& second_team);
