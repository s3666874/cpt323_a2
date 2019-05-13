#include "datastructure.h"
#pragma once

namespace cpt323::list
{
        struct node
        {
                private:
                        std::unique_ptr<node> next;
                        std::string data;

                friend struct list;

                node(const std::string& newstr)
                {
                        data = newstr;
                        next = nullptr;
                }

                void set_next(std::unique_ptr<node>&& next);

                virtual ~node()
                {
                }
        };

        struct list: public cpt323::datastructure::datastructure
        {
                private:
                        std::unique_ptr<node> head;
                        std::size_t num_elts;

                void add(const std::string&);
                std::unique_ptr<cpt323::list::list> readfile(std::string_view);

                virtual ~list(void)
                {
                }
        };
}