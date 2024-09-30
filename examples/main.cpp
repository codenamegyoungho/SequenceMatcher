#include "SequenceMatcher.h" 

int main() {
    std::string seq1 = "ATGCTAGCTAG"; 
    std::string seq2 = "ATGCGAGCTAC"; 

    SequenceMatcher matcher(seq1, seq2);
    matcher.find_matches(); 
    return 0;
}
