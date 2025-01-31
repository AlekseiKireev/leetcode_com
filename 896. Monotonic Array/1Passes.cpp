bool isMonotonic(vector<int>& A) {
    if (A.empty()) return true; // Пустой массив считается монотонным

    bool increasing = true, decreasing = true;

    for (size_t i = 1; i < A.size(); ++i) {
        if (A[i] > A[i - 1]) {
            decreasing = false; // Если есть возрастание, то убывающая монотонность нарушена
        }
        if (A[i] < A[i - 1]) {
            increasing = false; // Если есть убывание, то возрастающая монотонность нарушена
        }
    }

    return increasing || decreasing;
}
