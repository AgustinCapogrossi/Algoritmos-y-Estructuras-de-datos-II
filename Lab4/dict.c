#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"
#include "key_value.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

dict_t dict_empty() {
    dict_t dict = NULL;
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(def != NULL);
    if(dict != NULL){
    	if (key_less(dict->key, word)){
    		dict->right = dict_add(dict->right, word, def);
    	}
    	if(!key_less(dict->key,word)){
    	    	dict->left = dict_add(dict->left, word, def);
    	}
    	if (key_eq(dict->key,word)){
    		dict->value = def;
    	}
    }
    else{
    	dict = (dict_t)calloc(1,sizeof(struct _node_t));
    	dict->key = word;
    	dict->value = def;
    	dict->right = NULL;
    	dict->left = NULL;
    }
    //assert(value_eq(def, dict_search(dict, word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    key_t def=NULL;
    //assert(dict != NULL && word != NULL);
	if (key_eq(word,dict->key)){
		def = dict->value;
	}
	else{
		if(key_less(dict->key,word) && dict->right!=NULL){
			def = dict_search(dict->right,word);
		}
		if(!(key_less(dict->key,word)) && dict->left!=NULL){
			def = dict_search(dict->left,word);
		}
	}
    //assert((def==NULL && !dict_exists(dict, word)) || def != NULL);
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    assert(word != NULL);
	bool b = false;
	if (dict!=NULL){
	if (key_eq(dict->key,word)){
		b = true;
	}
	else {
		if(key_less(dict->key,word) && dict->right != NULL){
			b = dict_exists(dict->right,word);
		}
		if(!key_less(dict->key,word) && dict->left != NULL){
			b = dict_exists(dict->left,word);
		}
	}
	}
	return b;
}

unsigned int dict_length(dict_t dict) {
    //assert(dict != NULL);
	unsigned int dizq, dder, n;
	n = 0u;
    if (dict == NULL){
    	return n;
    }
    else{
    dizq = dict_length(dict->left);
    dder = dict_length(dict->right);
    n = dizq+dder+1u;
    }
    return n;
}

dict_t dict_remove(dict_t dict, key_t word) {
    assert(word != NULL);
    dict_t temp, temp2;
    temp = dict;
    if (key_less(dict->key, word)){
    	dict->right = dict_remove(dict->right,word);
    }
    if (!key_less(dict->key,word)){
    	dict->left = dict_remove(dict->left,word);
    }
    if (key_eq(dict->key, word)){
    	if(dict->left == NULL && dict->right != NULL) {
    		dict = dict->right;
    		dict->key = temp->key;
			dict->value = temp->value;		 	
    	}
    	if(dict->right == NULL && dict->left != NULL) {
    		temp = dict->left;
    		dict->key = temp->key;
			dict->value = temp->value; 	
    	}
    	if(dict->left == NULL && dict->right == NULL) {
    		free(dict);
    		dict = NULL;    	
    	}
    	if(dict->left != NULL && dict->right != NULL){
    		temp = dict;
    		temp2 = dict->left;
    		while (temp->right != NULL){
    			temp2 = temp;
    			temp = dict->right;	
    		}
    		if (temp != dict){
    			temp = NULL;
    			dict->left = temp2->left;
    		}
    	dict->key = temp2->key;
    	dict->value = temp2->value;
    	}    	
    }
    free(temp);
    free(temp2);
    assert(dict != NULL && !dict_exists(dict, word));
    return dict;
  }


dict_t dict_remove_all(dict_t dict) {
    //assert(dict != NULL);
    if (dict!=NULL){
    	if (dict->left!=NULL){
    		dict->left = dict_remove_all(dict->left);
    	if (dict->right){
    		dict->right = dict_remove_all(dict->right);  
	}
	}
	key_destroy(dict->key);
	value_destroy(dict->value);
	free(dict);
	dict=NULL;
    }
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert(file != NULL);
    if(dict!=NULL){
    	if (dict->left != NULL){
    		dict_dump(dict->left, file);
    	}
    	if(dict->right != NULL){
    		dict_dump(dict->right,file);
    	}
	key_dump(dict->key,file);
	fprintf(file, ":");
	value_dump(dict->value,file);
	fprintf(file, "\n");
	
    
    }
    assert(dict != NULL);
}

dict_t dict_destroy(dict_t dict) {
    //assert(dict != NULL);
    dict = dict_remove_all(dict);
    assert(dict == NULL);
    return dict;
}

