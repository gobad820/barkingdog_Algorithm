#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Polynomial;

class Term{
  friend Polynomial;
  friend bool compare(const Term a, const Term b);
  friend ostream& operator<<(ostream& os, const Polynomial& poly);
  friend istream& operator>>(istream& is, Polynomial& poly);
  private:
    float coef;
    int exp;
};

class Polynomial{
  public:
    Polynomial(); // polynomial p(x) = 0
    Polynomial(int capa);
    void NewTerm(const float coef, const int exp);
    Polynomial Add(Polynomial poly);
    Polynomial Multi(Polynomial poly);
    float Eval(float t);
    int TermNumber(){return terms;}
    friend ostream& operator<<(ostream& os, const Polynomial& poly);
    friend istream& operator>>(istream& is, Polynomial& poly);
  public:
    Term* termArray;
    int capacity;
    int terms;
};

Polynomial::Polynomial(){
  termArray = (Term*)malloc(sizeof(Term));
  capacity = 0;
  terms = 0;
}

Polynomial::Polynomial(int capa){
  termArray = (Term*)malloc(sizeof(Term)*capa);
  capacity = capa;
  terms = 0;
}

void Polynomial::NewTerm(const float theCoef, const int theExp){
  if(terms == capacity){
    capacity *= 2;
    Term* temp = new Term[capacity];
    copy(termArray, termArray+terms, temp);
    delete []termArray;
    termArray = temp;
  }
  termArray[terms].coef = theCoef;
  termArray[terms++].exp = theExp;
}

Polynomial Polynomial::Add(Polynomial b){
  Polynomial c;
  int apos = 0; int bpos = 0;
  while(apos < terms && bpos < b.terms){
    if(termArray[apos].exp == b.termArray[bpos].exp){
      float t = termArray[apos].coef + b.termArray[bpos].coef;
      if(t) c.NewTerm(t, termArray[apos].coef);
      apos++, bpos++;
    }
    else if(termArray[apos].exp < b.termArray[bpos].exp){
      c.NewTerm(b.termArray[bpos].coef,b.termArray[bpos].exp);
      bpos++;
    }
    else{
      c.NewTerm(termArray[apos].coef, termArray[apos].exp);
      apos++;
    }
  }
  for(;apos < terms ; apos++) c.NewTerm(termArray[apos].coef, termArray[apos].exp);
  for(;bpos < b.terms ; bpos++) c.NewTerm(b.termArray[bpos].coef, b.termArray[bpos].exp);
  return c;
}

ostream& operator<<(ostream& os, const Polynomial& poly){  
  for(int i = 0 ; i < poly.terms-1 ; i++)
    os << poly.termArray[i].coef << "x ^ " << poly.termArray[i].exp << " + ";
  os << poly.termArray[poly.terms-1].coef;
  if(poly.termArray[poly.terms-1].exp != 0)
    os << "x";
  return os;
}

bool compare(const Term a, const Term b){
  if(a.exp > b.exp) return true;
  return false;
}

istream& operator>>(istream& is, Polynomial& poly){
  for(int i = 0 ; i < poly.capacity ; i++){
    is >> poly.termArray[i].exp >> poly.termArray[i].coef;
    if(poly.termArray[i].coef == 0 && poly.termArray[i].exp == 0)
      break;
    poly.terms++;
  }
  sort(poly.termArray,poly.termArray+poly.terms,compare);
  return is;
}

float Polinomial::Eval(float t){
  float result = 0;
  for(int i = 0 ; i < this->terms ; i++){
    float temp = 1;
    for(int j = 0 ; j < i ;j++) temp *= t;
    result += this->termArray[i].coef * temp;
  }
}
int main(int argc, char const *argv[]){
  Polynomial a(4);
  Polynomial b(3);
  Polynomial o(5);
  cin >> a;
  cout << a << endl;
  cin >> b;
  cout << b;
  return 0;
}
