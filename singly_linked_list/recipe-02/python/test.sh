#!/usr/bin/env bash

rm -f result.log
python3 -m test_singly_linked_list >> result.log
python3 -m test_delete_tail >> result.log
python3 -m test_integer_list >> result.log
python3 -m test_list_reverse >> result.log
python3 -m test_list_sort >> result.log
