//
// Created by endargon on 11/30/16.
//

#ifndef SFML_DEMO_STORAGE_H
#define SFML_DEMO_STORAGE_H
template< typename T, int N >
class storage {
public:
   void add( const T & p ){
      if( count < N ){
         store[ count ] = p;
         ++count;
      }
   }

   T * begin(){ return store;  }
   T * end(){ return store + count; }

   const T * begin() const { return store;  }
   const T * end() const { return store + count; }

private:
   T store[ N ];
   int count = 0;
};

#endif //SFML_DEMO_STORAGE_H
