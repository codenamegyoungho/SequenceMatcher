#ifndef SEQUENCEMATCHER_H 
#define SEQUENCEMATCHER_H 
#include <string> 

class SequenceMatcher {
private:
    std::string seq1; 
    std::string seq2; 
    std::string match_line;
    double match_percentage; 

public:
    SequenceMatcher(const std::string& s1, const std::string& s2); 
    void find_matches(); 
    std::string get_seq1() const {return seq1;} 
    std::string get_seq2() const {return seq2;} 
    std::string get_match_line() const {return match_line;} 
    double get_match_percentage() const {return match_percentage;} 

private:
    std::string to_uppercase(const std::string& s1); 
    std::string pad_sequence(const std::string& seq, size_t target_length);
};

#endif
