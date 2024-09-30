#include "SequenceMatcher.h"
#include <iostream> 
#include <algorithm>
#include <iomanip>

SequenceMatcher::SequenceMatcher(const std::string& s1, const std::string& s2) {
    seq1 = to_uppercase(s1);
    seq2 = to_uppercase(s2); 
    match_percentage = 0.0; 
}

std::string SequenceMatcher::to_uppercase(const std::string& s) {
    std::string result = s; 
    std::transform(result.begin(),result.end(), result.begin(), [](unsigned char c) {return std::toupper(c);}); 
    return result;
}

std::string SequenceMatcher::pad_sequence(const std::string& seq, size_t target_length) {
    if (seq.length() >= target_length) {
        return seq;
    }
    return seq + std::string(target_length - seq.length(), ' ');
}

void SequenceMatcher::find_matches() {
    size_t len1 = seq1.length(); 
    size_t len2 = seq2.length(); 
    size_t max_len = std::max(len1,len2); 
    
    std::string padded_seq1 = pad_sequence(seq1, max_len); 
    std::string padded_seq2 = pad_sequence(seq2, max_len); 

    match_line = ""; 
    size_t match_count = 0; 

    for (size_t i = 0; i < max_len; i++) {
        if (padded_seq1[i] == padded_seq2[i] && padded_seq1[i] != ' '){
            match_line += '|'; 
            match_count++; 
        }
        else {
            match_line += ' ';
        }
    }
    match_percentage = (static_cast<double>(match_count) / max_len) * 100.0; 
    std::cout << "Sequence 1: " << padded_seq1 << std::endl;
    std::cout << "            " << match_line << std::endl; 
    std::cout << "Seqeucne 2: " << padded_seq2 << std::endl; 
    std::cout << "Matching Rate: " << std::setprecision(2) << match_percentage << "%" << std::endl; 
} 
