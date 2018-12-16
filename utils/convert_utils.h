#include <vector>
#include <string>

// convert sequence<string> to vector<string>
template <typename SeqType>
std::vector<std::string> secToVector(const SeqType& stringSeq) {
    std::vector<std::string> result;
    for(int i = 0; i < stringSeq.length(); ++i) {
        result.push_back(std::string(stringSeq[i]));
    }
    return result;
}

// convert vector<string> to sequence<string>
template <typename SeqType>
SeqType vectorToSeq(const std::vector<std::string> &vector) {
    SeqType result;
    result.length(vector.size());
    for (int i = 0; i < vector.size(); ++i) {
        result[i] = vector[i].c_str();
    }
    return result;
}
