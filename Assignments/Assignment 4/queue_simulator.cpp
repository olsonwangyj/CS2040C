#include "queue_simulator.h"
#include "heap.hpp"

vector<Customer> QueueSimulator::simulateQueue(
    const vector<Customer>& customers) {
  // TODO: Implement this function.
    vector<Customer> result;
    vector<int> server_free_time(_num_servers, 0);
    int customer_index = 0;
    int current_time = 0;


    if (_priority_order) {
        Heap<Customer> customerHeap;
        Customer::set_compare_by_processing_time(true);
        
        while (customer_index < customers.size() || !customerHeap.empty()) {
            while (customer_index < customers.size() && customers[customer_index].arrival_time() <= current_time) {
                customerHeap.insert(customers[customer_index]);
                customer_index++;
            }

            if (!customerHeap.empty()) {
                Customer customer = customerHeap.extractMax();
                int earliest_server_index = std::min_element(server_free_time.begin(), server_free_time.end()) - server_free_time.begin();
                int start_time = std::max(customer.arrival_time(), server_free_time[earliest_server_index]);

                customer.set_service_time(start_time);
                server_free_time[earliest_server_index] = start_time + customer.processing_time();

                result.push_back(customer);
                earliest_server_index = std::min_element(server_free_time.begin(), server_free_time.end()) - server_free_time.begin();
                current_time = server_free_time[earliest_server_index];
            }
            else {
                current_time++;
            }
        }
    }
    else {
        for (Customer customer : customers) {
            int earliest_server_index = std::min_element(server_free_time.begin(), server_free_time.end()) - server_free_time.begin();
            int start_time = std::max(customer.arrival_time(), server_free_time[earliest_server_index]);

            customer.set_service_time(start_time);
            server_free_time[earliest_server_index] = start_time + customer.processing_time();

            result.push_back(customer);
        }
    }

  return result;
}
