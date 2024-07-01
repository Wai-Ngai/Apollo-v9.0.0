class Student {
public:
  Student(int id, std::string name): id_(id), name_(name) {};
  ~Student() = default;
  void SetAge(int age) { age_ = age; }
  int GetAge() const { return this->age_; }
  void SetScore(int score) { score_ = score; }
  int GetScore() const { return this->score_; }
private:
  int id_;
  std::string name_;
  int age_;
  int score_;
};