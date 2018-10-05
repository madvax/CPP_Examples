#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

extern std::string database_filename = "database.db" ;
extern char        *create_orders_table              ;
extern char        *create_order_items_table         ;

/* Create orders table SQL */
create_orders_table = "CREATE TABLE ORDERS("                     \
                      "   ORDER_ID INT   PRIMARY KEY NOT NULL,"  \
                      "   CASHIER  TEXT              NOT NULL,"  \
                      "   DATE     TEXT              NOT NULL,"  \
                      "   TIME     TEXT              NOT NULL);" ;


/* Create order items table SQL */
create_order_items_table = "CREATE TABLE ORDER_ITEMS("                   \
                           "   ITEM_ID     INT   PRIMARY KEY NOT NULL,"  \
                           "   ORDER_ID    INT               NOT NULL,"  \
                           "   DESCRIPTION TEXT              NOT NULL,"  \
                           "   PRICE       REAL              NOT NULL);" ;



extern  void         add_order(std::string order_id, std::string cashier);
extern  void         add_item_to_order(std::string order_id, std::string description, float price );
extern  std::string  get_order(std::string order_id);


#endif

