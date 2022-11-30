#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Creating a struct for person. 
// person contains first name, middle and last
// Since it is a Linked list, we also maintain a pointer named next in the struct. 
struct Person{
    char first_name[30], middle_name[30], last_name[30];
    struct Person *next;
};


// maintaing a global
struct Person *head = NULL;

void print_namelist(){
    struct Person *curr = head;
    while(curr != NULL){
        printf("|  %s %s %s  | ", curr->first_name, curr->middle_name, curr->last_name);
        curr = curr->next;
    }
    printf("\n");
}

// comparison function that compares 2 persons on the basis of their first name, then last names. 
int compare(struct Person first_person, struct Person second_person){
    if(!strcmp(first_person.first_name, second_person.first_name)){
        if(!strcmp(first_person.middle_name, second_person.middle_name)){
            return strcmp(first_person.last_name, second_person.last_name);
        }
        else return strcmp(first_person.middle_name, second_person.middle_name);
    }
    else strcmp(first_person.first_name, second_person.first_name);
}


// Insert function: insert a person. does not return anything, because head is global .
void insert_person(struct Person *person_ptr){
    if(head == NULL){
        head = person_ptr;
        return;
    }
    
    // If person_ptr is lex. smaller than head
    if(compare(*person_ptr, *head) < 0){
        struct Person *tmp_ptr = head;
        head = person_ptr;
        head->next = tmp_ptr;
        return;
    }
    
    // Iterate until the next element is greater than the current person's name
    printf("(%s)", head->first_name);
    struct Person *prev = head;
    struct Person *curr = head->next;
    while(curr != NULL && compare(*person_ptr, *curr) >= 0){
        struct Person *tmp_ptr = curr; 
        curr = curr->next;
        prev = tmp_ptr;
    }
    
    // Insert the person
    person_ptr->next = curr;
    prev->next = person_ptr;
}


//delete: delete the given person struct as input;
// donot return anything after modifying the list because head is global 
void delete_person(struct Person *toBeDeleted){
    if(head == NULL || toBeDeleted == NULL){
        printf("The person to be deleted does not exists");
        return;
    }
    
    if(head == toBeDeleted){
        printf("Person to be deleted was head of the list, hence deleting head");
        head = head->next;
        return;
    }
    
    struct Person* p = NULL; 
    p = head;
    // seearch for the node to be deleted. 
    // maintain a previous node as "p"
    // make p's next point to p's next's next
    while(p!=NULL){
        
        if(p->next == toBeDeleted){
            break;
        }
        p = p->next;
    }
    // if not found, do nothing. 
    if(p->next == NULL) {
        printf("The person to be deleted does not exists");
        return;
    }

    //deleting the node after 'p'
    p->next = p->next->next;
    return;
    
}




int main() {

    int num_names;
    printf("Enter the number of names: "); 
    
    // input from console
    scanf("%d", &num_names);

    for(int person = 1; person <= num_names; person++){
        // Get input
        printf("\n\nEnter space separated first, middle and last name of person #%d: ", person);
        struct Person *current_person = NULL;
        current_person = (struct Person*) malloc(sizeof(struct Person));

        //input from console 
        scanf("%s%s%s", current_person->first_name, current_person->middle_name, current_person->last_name);
        current_person->next = NULL;

        insert_person(current_person);
        printf("\nList after inserting person #%d: ", person);
        print_namelist();
    }
    
    printf("\nList after deleting");
    delete_person(head->next);
    print_namelist();
    return 0;
}