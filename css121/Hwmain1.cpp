#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>



// Define a structure to represent a person's attributes
struct Person {
  std::string Name;
  std::string Sex;
  double Ne;
  double Ni;
  double Te;
  double Ti;
  double Se;
  double Si;
  double Fe;
  double Fi;
  std::string Type;
  std::string NickName;
};

// Calculate the Euclidean distance between two people
double calculateDistance(const Person& p1, const Person& p2) {
  double distance = 0.0;

  distance += pow(p1.Ne - p2.Ne, 2);
  distance += pow(p1.Ni - p2.Ni, 2);
  distance += pow(p1.Te - p2.Te, 2);
  distance += pow(p1.Ti - p2.Ti, 2);
  distance += pow(p1.Se - p2.Se, 2);
  distance += pow(p1.Si - p2.Si, 2);
  distance += pow(p1.Fe - p2.Fe, 2);
  distance += pow(p1.Fi - p2.Fi, 2);

  return sqrt(distance);
}

// Find the K nearest neighbors to a given person
std::vector<Person> findKNearestNeighbors(const std::vector<Person>& people,
                                          const Person& testPerson, int k) {
  std::vector<Person> neighbors;

  // Calculate the distance between the test person and each person in the array
  std::vector<double> distances;
  for (const auto& person : people) {
    double distance = calculateDistance(testPerson, person);
    distances.push_back(distance);
  }

  // Find the K nearest neighbors based on the calculated distances
  for (int i = 0; i < k; ++i) {
    auto minDistIt = std::min_element(distances.begin(), distances.end());
    int minDistIndex = minDistIt - distances.begin();
    neighbors.push_back(people[minDistIndex]);
    distances[minDistIndex] = INFINITY;
  }

  return neighbors;
}

// Predict the MBTI type of a given person using KNN
std::string predictMBTITypeKNN(const std::vector<Person>& people,
                               const Person& testPerson, int k) {
  // Find the K nearest neighbors to the test person
  auto neighbors = findKNearestNeighbors(people, testPerson, k);

  // Count the number of occurrences of each MBTI type among the neighbors
  std::vector<int> counts(16, 0);
  for (const auto& neighbor : neighbors) {
    if (neighbor.Type == "ISTJ") {
      ++counts[0];
    } else if (neighbor.Type == "ISFJ") {
      ++counts[1];
    } else if (neighbor.Type == "INFJ") {
      ++counts[2];
    } else if (neighbor.Type == "INTJ") {
      ++counts[3];
    } else if (neighbor.Type == "ISTP") {
      ++counts[4];
    } else if (neighbor.Type == "ISFP") {
      ++counts[5];
    } else if (neighbor.Type == "INFP") {
      ++counts[6];
    } else if (neighbor.Type == "INTP") {
      ++counts[7];
    } else if (neighbor.Type == "ESTP") {
      ++counts[8];
    } else if (neighbor.Type == "ESFP") {
      ++counts[9];
    } else if (neighbor.Type == "ENFP") {
     ++counts[10];
    } else if (neighbor.Type == "ENTP") {
    ++counts[11];
    } else if (neighbor.Type == "ESTJ") {
    ++counts[12];
    } else if (neighbor.Type == "ESFJ") {
    ++counts[13];
    } else if (neighbor.Type == "ENFJ") {
    ++counts[14];
    } else if (neighbor.Type == "ENTJ") {
    ++counts[15];
    }
}

// Find the most common MBTI type among the neighbors
int maxCountIndex = 0;
for (int i = 1; i < counts.size(); ++i) {
if (counts[i] > counts[maxCountIndex]) {
maxCountIndex = i;
}
}

// Return the most common MBTI type
static const std::string MBTI_TYPES[] = {
"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP",
"ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ"
};
return MBTI_TYPES[maxCountIndex];
}

int main() {
// Define an array of people to use as the training data
std::vector<Person> people = {
    {"Warin Wattanapornprom", "Male", 32, 32, 27, 36, 29, 31, 28, 23, "INTP", "Aj.Yong"},
    {"Kornkanok Welagert", "Female", 28.4, 29.4, 29, 34, 27, 24, 23, 21, "ISTP", "Somchun"},
    {"Kritamet Chongcharoen", "Male", 22.4, 21.2, 20, 27, 21, 30, 17, 21, "INTP", "Owen"},
    {"Kunakron Tana", "Male", 30, 24, 25, 27, 23, 28, 26, 17, "ENTP", "Title"},
    {"Chinnapt Sukthong", "Male", 21, 25.6, 29, 30, 28, 29, 28, 30, "ISTJ", "Nai"},
    {"Chinavat Nachaithong", "Male", 35.6, 37.8, 27, 28, 28, 29, 36, 35, "ENFP", "Mon"},
    {"Teekamon Chaiwongwutikul", "Female", 23.4, 26, 27, 30, 28, 31, 26, 21, "ISTJ", "Queen"},
    {"Dollatham Charoethammkic", "Male", 37, 47.8, 43, 47, 47, 45, 37, 43, "INTJ", "Oat"},
    {"Thiyada Kittiwithitkun", "Female", 34, 26.6, 26, 29, 28, 34, 33, 32, "ESFJ", "Por"},
    {"Thidarat Sitthidech", "Female", 29, 31.2, 26, 27, 17, 32, 33, 26, "INFJ", "Louknam"},
    {"Phumiphat Santithawornying", "Male", 26.2, 28.6, 21, 25, 30, 31, 32, 20, "INFJ", "Phu"},
    {"Manotham Damnoen", "Male", 35.4, 29.4, 26, 28, 28, 19, 29, 27, "ENTP", "Auan"},
    {"Wachirawit Intapan", "Male", 29, 25, 21, 23, 32, 36, 14, 19, "INTP", "Guy"},
    {"Warit Teerapong", "Male", 35.8, 28.4, 28, 32, 18, 32, 31, 35, "INFP", "Smart"},
    {"Sasima Phanta", "Female", 20.4, 22.4, 32, 32, 24, 28, 25, 16, "ESTJ", "Ja"},
    {"Artima Rojanagamonson", "Female", 34.8, 28, 35, 32, 26, 32, 28, 17, "ESTJ", "Belle"},
    {"Koraphan Manitha", "Male", 22.4, 31.4, 33, 34, 33, 35, 25, 23, "INTP", "Riw"},
    {"Ganyawee Sanghom", "Female", 34.4, 36.8, 24, 32, 28, 35, 32, 34, "INFP", "Pearwa"},
    {"Kimhan Jongjaidee", "Male", 38.2, 32.2, 35, 34, 17, 28, 28, 18, "ENTP", "Kim"},
    {"Chaithawat Saklang", "Male", 24.8, 24.6, 29, 26, 29, 28, 29, 29, "ESFP", "Art"},
    {"Nattanischa Aumpornchairuch", "Female", 29.2, 23.8, 28, 30, 22, 31, 32, 21, "ESTJ", "Love"},
    {"Thanapong Simmanee", "Male", 23.4, 30.8, 35, 41, 31, 36, 39, 29, "ISFJ", "Yu"},
    {"Thidarut Deeramies", "Female", 31.6, 36.4, 24, 32, 32, 30, 24, 20, "ISTP", "Aum"},
    {"Panachai Suvimolopas", "Male", 34.2, 24.6, 31, 35, 33, 25, 32, 25, "ENTP", "Bank"},
    {"Pichayut Sombat", "Male", 32.2, 25.2, 29, 27, 30, 31, 25, 26, "INTP", "Field"},
    {"Poomthai Promkote", "Male", 39.6, 46.8, 33, 36, 32, 36, 30, 30, "INTP", "Poom"},
    {"Lalhada Suttiprapha", "Female", 27.8, 23.4, 21, 27, 24, 35, 26, 22, "ISFJ", "Pleng"},
    {"Santijit Kamnak", "Male", 22.4, 20.6, 26, 26, 26, 30, 22, 25, "ISTJ", "Ono"},
    {"Kantinan Kuikeaw", "Male", 13.8, 16, 33, 31, 35, 32, 23, 16, "ESTJ", "Fig"},
    {"Chothanin Thitisrirat", "Male", 29.8, 28, 24, 26, 29, 32, 36, 18, "ESFJ", "Maithong"},
    {"Yanisa Mungkarotai", "Female", 23, 26.6, 28, 25, 17, 29, 29, 31, "INTJ", "Zom"},
    {"Jessada Pranee", "Male", 27.8, 24.2, 32, 29, 18, 20, 13, 31, "INTP", "Jack"},
    {"Suphanut Chanroong", "Male", 34.6, 32, 25, 29, 23, 24, 29, 26, "ENFP", "Beck"},
    {"Keerataphan Malai", "Male", 15.6, 28.2, 21, 31, 19, 28, 18, 23, "ISTP", "New"},
    {"Thanachot Wongyai", "Male", 24.8, 19.2, 25, 30, 22, 28, 19, 25, "INTP", "Sian"},
    {"Pawinnarut Pornpanarat", "Male", 47.4, 31.2, 36, 32, 36, 37, 29, 31, "ENTP", "Captain"},
    {"Phirada Chemmanmud", "Female", 23.6, 22.2, 28, 35, 27, 40, 23, 22, "ISTJ", "Aida"},
    {"Phattawee Witthayapanyanont", "Male", 37.2, 23.6, 36, 39, 34, 33, 31, 16, "INTP", "Jai"},
    {"Sathapana Tinop", "Male", 23.2, 30.6, 30, 36, 19, 21, 4, 28, "INTP", "Guy"},
    {"Pattarachanon Uraiwichaikul", "Male", 35.6, 28.4, 36, 38, 36, 28, 29, 30, "ESTJ", "Deaw"},
    {"Krantharat Ratchart", "Female", 26.6, 21, 27, 27, 25, 26, 22, 19, "ESTJ", "Tennis"},
    {"Pasin Laopooti", "Male", 32.8, 31, 28, 37, 29, 38, 25, 29, "INTP", "Jane"},
    {"Patchnida Hemwannanukul", "Female", 29.8, 23.4, 30, 26, 27, 30, 29, 29, "ESTJ", "Pin"},
    {"Nakamon Yongpaisarn", "Female", 28, 24, 31, 31, 29, 37, 28, 28, "INFP", "Be"},
    {"Atchima Nateepradap", "Female", 17.6, 22.2, 28, 25, 20, 35, 27, 18, "ISTJ", "Aut"},
    {"Natthapon Tanateeraanan", "Male", 24.6, 22, 32, 32, 36, 38, 35, 27, "ESTP", "Nutsu"},
    {"Naphatchanun Suecey", "Female", 23.4, 26, 31, 33, 24, 27, 31, 21, "ESFJ", "Hong"},
    {"Narutchai Mauensaen", "Male", 33.2, 27, 32, 28, 33, 32, 39, 40, "INFP", "FLUK"},
    {"Natchapon Ponlaem", "Male", 33.6, 32, 34, 31, 31, 37, 36, 29, "ENTP", "Two"},
    {"Phacharaphon Aiamphan", "Male", 36.4, 36.4, 34, 32, 31, 31, 37, 29, "INTP", "Folk"},
    {"Sarita Tongsawat", "Female", 33, 33.6, 25, 29, 25, 28, 35, 34, "INFJ", "Gam"},
    {"Thitirat Atchayasoontorn", "Female", 31.1, 23.2, 23, 34, 23, 33, 24, 17, "INTP", "Mook"},
    {"Puchit Ketsomboon", "Male", 25.6, 35.2, 29, 27, 26, 38, 21, 26, "INTP", "Heart"},
    {"Sarun Chomchana","Male",34.4,29,35,39,35,37,31,30,"ESTJ","Four"}

};

// Define a test person to predict the MBTI type of
Person testPerson = {"Pattanapol Saelim", "Male", 41.8,37.8,28,21,34,34,33,23, "", "Jaylerr"};

// Find the predicted MBTI type using KNN with K=3
int k = 3;
std::string predictedType = predictMBTITypeKNN(people, testPerson, k);

// Print the predicted MBTI type
std::cout << "Predicted MBTI type for " << testPerson.Name << ": " << predictedType << std::endl;

return 0;
}
