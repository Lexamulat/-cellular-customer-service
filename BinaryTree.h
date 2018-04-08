#pragma once
#include "tree.h"
#include <memory>
class BinaryTree

{
public:

	BinaryTree();
	//void SearchForDel(std::shared_ptr<tree>& head);
	void Rec(std::shared_ptr<tree> Current, int num, bool &b);
	void PreStraight();
	void StraightPrint(std::shared_ptr<tree> head);
	std::shared_ptr<tree> removemin(std::shared_ptr<tree>& p);
	std::shared_ptr<tree> FindMin(std::shared_ptr<tree>& p);
	void Preremove();
	std::shared_ptr<tree> remove(std::shared_ptr<tree> p, int pasnum);
	void Preshow();
	void ShowTree(std::shared_ptr<tree> head, int up);
	void Add(std::shared_ptr<tree> &head, std::shared_ptr<tree> temp, std::shared_ptr<tree> &current);
	void Create();
	void Balance(std::shared_ptr<tree> &head);
	void fixheight(std::shared_ptr<tree> &head);
	unsigned int height(std::shared_ptr<tree> &head);
	~BinaryTree();
	std::shared_ptr<tree> GetHead();
	void LeftRotate(std::shared_ptr<tree> &head);
	void RightRotate(std::shared_ptr<tree> &head);

private:
	std::shared_ptr<tree> current = nullptr;
	std::shared_ptr<tree> head = nullptr;
};

