#include <iostream>
#include <string>

struct Recipe {
	std::string recipeName;
	std::int16_t recipePrice;
	Recipe* left;
	Recipe* right;
};


Recipe* createRecipe(std::string recipeName, std::int_fast16_t recipePrice) {
	Recipe* newRecipe = new Recipe; // initialize new node

	newRecipe->recipeName = recipeName; // set the value of newRecipe to recipename from parameters
	newRecipe->recipePrice = recipePrice; // set the value of recipePrice from parameters

	newRecipe->left = newRecipe->right = nullptr; // initialize left and right to null


	return newRecipe; //return the new recipe
}

int getRecipeLength(Recipe* root) {
	if (root == nullptr) {
		return 0;
	}

	int right = getRecipeLength(root->right);
	int left = getRecipeLength(root->left);
	int count = 1 + right + left;

	return count;

}

Recipe* searchRecipe(Recipe* root , std::string recipeNameTosearch) {
	if (root == nullptr) {
		std::cout << "No recipe available at the moment" << std::endl;
		return root;
	}
	
	if (recipeNameTosearch == root->recipeName) {
		return root;
	}

	if (recipeNameTosearch < root->recipeName) {
		return searchRecipe(root->left, recipeNameTosearch);
	}


	return searchRecipe(root->right, recipeNameTosearch);


}



int main() {
	int recipeLength{};
	Recipe* root = createRecipe("root recipe", 1000);
	root->left = createRecipe("left child", 5000);
	root->right = createRecipe("right child", 1000);
	root->left->left = createRecipe("left left child", 1000);

	Recipe* FindRecipe = searchRecipe(root, "left c2hild");




	std::cout << "The recipe search name: " << FindRecipe->recipeName << std::endl;
	std::cout << "the recipe search price: " << FindRecipe->recipePrice << std::endl;
	std::cout << "The length is: " << getRecipeLength(root) << std::endl;

	
	std::cout << "hello world";

	return 0;
}