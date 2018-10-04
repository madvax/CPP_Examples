// May require:
// sudo apt-get install uuid-dev
// or
// sudo yum install uuid-devel
//
// link with g++ -l uuid

#include <uuid/uuid.h>
#include <string>

std::string generate_uuid(void) {

   uuid_t  id; // Generic UUID type for generating the unique Order ID
   char *order_string = new char[100] ; //
   // Generate the unique Order ID
   uuid_generate(id);
   uuid_unparse(id, order_string);

   return order_string;

}




