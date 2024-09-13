/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:49:33 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/11 22:21:22 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

t_stack		*stack;

void	setUp(void)
{
	exit_pass = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		TEST_ABORT();
	stack->name = 't';
	stack->stack = NULL;
}

void	tearDown(void)
{
}

static void	test_input_regularInput(void)
{
	int		argc;
	char	*argv[6] = {"./push_swap", "1", "51", "2", "394", "4"};
	int		arg_int[5] = {1, 51, 2, 394, 4};
	int		i;
	t_list	*start;

	i = 0;
	argc = 6;
	input(argc, argv, stack);
	start = stack->stack;
	TEST_ASSERT_NOT_NULL_MESSAGE(stack->stack, "Returned NULL pointer.");
	while (start != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int[i++], *((int *)start->content));
		start = start->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc - 1, i,
		"Wrong number of elements in the list.");
	free_all(stack);
}

static void	test_input_intLimits(void)
{
	int		argc;
	char	*argv[4] = {"./push_swap", "2147483647", "-2147483648", "0"};
	int		arg_int[3] = {2147483647, -2147483648, 0};
	int		i;
	t_list	*start;

	i = 0;
	argc = 4;
	input(argc, argv, stack);
	start = stack->stack;
	TEST_ASSERT_NOT_NULL_MESSAGE(stack->stack, "Returned NULL pointer.");
	while (start != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int[i++], *((int *)start->content));
		start = start->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc - 1, i,
		"Wrong number of elements in the list.");
	free_all(stack);
}

static void	test_input_negativeNumbers(void)
{
	int		argc;
	char	*argv[6] = {"./push_swap", "-10", "5", "-01", "-0", "-4"};
	int		arg_int[5] = {-10, 5, -1, 0, -4};
	int		i;
	t_list	*start;

	i = 0;
	argc = 6;
	input(argc, argv, stack);
	start = stack->stack;
	TEST_ASSERT_NOT_NULL_MESSAGE(stack->stack, "Returned NULL pointer.");
	while (start != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int[i++], *((int *)start->content));
		start = start->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc - 1, i,
		"Wrong number of elements in the list.");
	free_all(stack);
}

static void	test_input_duplicates(void)
{
	int		argc;
	char	*argv[6] = {"./push_swap", "1", "5", "2", "1", "4"};

	exit_pass = 1;
	argc = 6;
	input(argc, argv, stack);
	TEST_FAIL_MESSAGE("Not exited");
}

static void	test_input_notNumber(void)
{
	int		argc;
	char	*argv[6] = {"./push_swap", "1", "five", "2", "1", "4"};

	exit_pass = 1;
	argc = 6;
	input(argc, argv, stack);
	TEST_FAIL_MESSAGE("Not exited");
}

static void	test_input_notNumber2(void)
{
	int		argc;
	char	*argv[6] = {"./push_swap", "1", "+5", "2", "1", "4"};

	exit_pass = 1;
	argc = 6;
	input(argc, argv, stack);
	TEST_FAIL_MESSAGE("Not exited");
}

static void	test_input_notNumber3(void)
{
	int		argc;
	char	*argv[6] = {"./push_swap", "1", "--5", "2", "1", "4"};

	exit_pass = 1;
	argc = 6;
	input(argc, argv, stack);
	TEST_FAIL_MESSAGE("Not exited");
}

static void	test_input_overInt(void)
{
	int		argc;
	char	*argv[6] = {"./push_swap", "2147483648"};

	exit_pass = 1;
	argc = 6;
	input(argc, argv, stack);
	TEST_FAIL_MESSAGE("Not exited");
}

static void	test_input_underInt(void)
{
	int		argc;
	char	*argv[6] = {"./push_swap", "-2147483649"};

	exit_pass = 1;
	argc = 6;
	input(argc, argv, stack);
	TEST_FAIL_MESSAGE("Not exited");
}

// Rules tests
static void	test_swap(void)
{
	t_stack	stack_a;
	t_list	stack1;
	t_list	stack2;
	t_list	stack3;
	t_list	stack4;
	t_list	stack5;
	int		content1;
	int		content2;
	int		content3;
	int		content4;
	int		content5;
	int		arg_int[5] = {2147483647, 0, -1234, -2147483648, 56789};
	int		argc;
	char	name;
	int		i;

	argc = 5;
	name = 'a';
	content1 = arg_int[1];
	content2 = arg_int[0];
	content3 = arg_int[2];
	content4 = arg_int[3];
	content5 = arg_int[4];
	stack1.content = &content1;
	stack1.next = &stack2;
	stack2.content = &content2;
	stack2.next = &stack3;
	stack3.content = &content3;
	stack3.next = &stack4;
	stack4.content = &content4;
	stack4.next = &stack5;
	stack5.content = &content5;
	stack5.next = NULL;
	stack_a.name = name;
	stack_a.stack = &stack1;
	ps_swap(&stack_a);
	i = 0;
	while (stack_a.stack != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int[i++], *((int *)stack_a.stack->content));
		stack_a.stack = stack_a.stack->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc, i,
		"Wrong number of elements in the stack.");
}

static void	test_swap_secondNULL(void)
{
	t_stack	stack_a;
	t_list	stack1;
	int		content1;
	int		arg_int[1] = {-42};
	int		argc;
	char	name;
	int		i;

	argc = 1;
	name = 'a';
	content1 = arg_int[0];
	stack1.content = &content1;
	stack1.next = NULL;
	stack_a.name = name;
	stack_a.stack = &stack1;
	ps_swap(&stack_a);
	i = 0;
	while (stack_a.stack != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int[i++], *((int *)stack_a.stack->content));
		stack_a.stack = stack_a.stack->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc, i,
		"Wrong number of elements in the stack.");
}

static void	test_swap_firstNULL(void)
{
	t_stack	stack_a;
	char	name;

	name = 'a';
	stack_a.name = name;
	stack_a.stack = NULL;
	ps_swap(&stack_a);
	TEST_ASSERT_NULL(stack_a.stack);
}

static void	test_push(void)
{
	t_stack	stack_a;
	t_list	stack1_a;
	t_list	stack2_a;
	t_list	stack3_a;
	int		content1_a;
	int		content2_a;
	int		content3_a;
	t_stack	stack_b;
	t_list	stack1_b;
	t_list	stack2_b;
	t_list	stack3_b;
	int		content1_b;
	int		content2_b;
	int		content3_b;
	int		arg_int_a[2] = {2147483647, 0};
	int		arg_int_b[4] = {-1234, -2147483648, 56789, 10};
	int		argc_a;
	int		argc_b;
	char	name_a;
	char	name_b;
	int		i;

	argc_a = 2;
	argc_b = 4;
	name_a = 'a';
	name_b = 'b';
	content1_a = arg_int_b[0];
	content2_a = arg_int_a[0];
	content3_a = arg_int_a[1];
	content1_b = arg_int_b[1];
	content2_b = arg_int_b[2];
	content3_b = arg_int_b[3];
	stack1_a.content = &content1_a;
	stack1_a.next = &stack2_a;
	stack2_a.content = &content2_a;
	stack2_a.next = &stack3_a;
	stack3_a.content = &content3_a;
	stack3_a.next = NULL;
	stack_a.name = name_a;
	stack_a.stack = &stack1_a;
	stack1_b.content = &content1_b;
	stack1_b.next = &stack2_b;
	stack2_b.content = &content2_b;
	stack2_b.next = &stack3_b;
	stack3_b.content = &content3_b;
	stack3_b.next = NULL;
	stack_b.name = name_b;
	stack_b.stack = &stack1_b;
	ps_push(&stack_a, &stack_b);
	i = 0;
	while (stack_a.stack != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int_a[i++], *((int *)stack_a.stack->content));
		stack_a.stack = stack_a.stack->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc_a, i,
		"Wrong number of elements in the stack.");
	i = 0;
	while (stack_b.stack != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int_b[i++], *((int *)stack_b.stack->content));
		stack_b.stack = stack_b.stack->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc_b, i,
		"Wrong number of elements in the stack.");
}

static void	test_push_fromNULL(void)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_list	stack1_b;
	t_list	stack2_b;
	t_list	stack3_b;
	int		content1_b;
	int		content2_b;
	int		content3_b;
	int		arg_int_b[3] = {-1234, -2147483648, 56789};
	int		argc_b;
	char	name_a;
	char	name_b;
	int		i;

	argc_b = 3;
	name_a = 'a';
	name_b = 'b';
	content1_b = arg_int_b[0];
	content2_b = arg_int_b[1];
	content3_b = arg_int_b[2];
	stack_a.stack = NULL;
	stack_a.name = name_a;
	stack1_b.content = &content1_b;
	stack1_b.next = &stack2_b;
	stack2_b.content = &content2_b;
	stack2_b.next = &stack3_b;
	stack3_b.content = &content3_b;
	stack3_b.next = NULL;
	stack_b.name = name_b;
	stack_b.stack = &stack1_b;
	ps_push(&stack_a, &stack_b);
	i = 0;
	while (stack_b.stack != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int_b[i++], *((int *)stack_b.stack->content));
		stack_b.stack = stack_b.stack->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc_b, i,
		"Wrong number of elements in the stack.");
	TEST_ASSERT_NULL(stack_a.stack);
}

static void	test_rotate(void)
{
	t_stack	stack_a;
	t_list	stack1;
	t_list	stack2;
	t_list	stack3;
	t_list	stack4;
	t_list	stack5;
	int		content1;
	int		content2;
	int		content3;
	int		content4;
	int		content5;
	int		arg_int[5] = {2147483647, 0, -1234, -2147483648, 56789};
	int		argc;
	char	name;
	int		i;

	argc = 5;
	name = 'a';
	content1 = arg_int[4];
	content2 = arg_int[0];
	content3 = arg_int[1];
	content4 = arg_int[2];
	content5 = arg_int[3];
	stack1.content = &content1;
	stack1.next = &stack2;
	stack2.content = &content2;
	stack2.next = &stack3;
	stack3.content = &content3;
	stack3.next = &stack4;
	stack4.content = &content4;
	stack4.next = &stack5;
	stack5.content = &content5;
	stack5.next = NULL;
	stack_a.name = name;
	stack_a.stack = &stack1;
	ps_rotate(&stack_a);
	i = 0;
	while (stack_a.stack != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int[i++], *((int *)stack_a.stack->content));
		stack_a.stack = stack_a.stack->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc, i,
		"Wrong number of elements in the stack.");
}

static void	test_rotate_one(void)
{
	t_stack	stack_a;
	t_list	stack1;
	int		content1;
	int		arg_int[1] = {-42};
	int		argc;
	char	name;
	int		i;

	argc = 1;
	name = 'a';
	content1 = arg_int[0];
	stack1.content = &content1;
	stack1.next = NULL;
	stack_a.name = name;
	stack_a.stack = &stack1;
	ps_rotate(&stack_a);
	i = 0;
	while (stack_a.stack != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int[i++], *((int *)stack_a.stack->content));
		stack_a.stack = stack_a.stack->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc, i,
		"Wrong number of elements in the stack.");
}

static void	test_rotate_NULL(void)
{
	t_stack	stack_a;
	char	name;

	name = 'a';
	stack_a.name = name;
	stack_a.stack = NULL;
	ps_rotate(&stack_a);
	TEST_ASSERT_NULL(stack_a.stack);
}

static void	test_rev_rotate(void)
{
	t_stack	stack_a;
	t_list	stack1;
	t_list	stack2;
	t_list	stack3;
	t_list	stack4;
	t_list	stack5;
	int		content1;
	int		content2;
	int		content3;
	int		content4;
	int		content5;
	int		arg_int[5] = {2147483647, 0, -1234, -2147483648, 56789};
	int		argc;
	char	name;
	int		i;

	argc = 5;
	name = 'a';
	content1 = arg_int[1];
	content2 = arg_int[2];
	content3 = arg_int[3];
	content4 = arg_int[4];
	content5 = arg_int[0];
	stack1.content = &content1;
	stack1.next = &stack2;
	stack2.content = &content2;
	stack2.next = &stack3;
	stack3.content = &content3;
	stack3.next = &stack4;
	stack4.content = &content4;
	stack4.next = &stack5;
	stack5.content = &content5;
	stack5.next = NULL;
	stack_a.name = name;
	stack_a.stack = &stack1;
	ps_rev_rotate(&stack_a);
	i = 0;
	while (stack_a.stack != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int[i++], *((int *)stack_a.stack->content));
		stack_a.stack = stack_a.stack->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc, i,
		"Wrong number of elements in the stack.");
}

static void	test_rev_rotate_one(void)
{
	t_stack	stack_a;
	t_list	stack1;
	int		content1;
	int		arg_int[1] = {-42};
	int		argc;
	char	name;
	int		i;

	argc = 1;
	name = 'a';
	content1 = arg_int[0];
	stack1.content = &content1;
	stack1.next = NULL;
	stack_a.name = name;
	stack_a.stack = &stack1;
	ps_rev_rotate(&stack_a);
	i = 0;
	while (stack_a.stack != NULL)
	{
		TEST_ASSERT_EQUAL(arg_int[i++], *((int *)stack_a.stack->content));
		stack_a.stack = stack_a.stack->next;
	}
	TEST_ASSERT_EQUAL_MESSAGE(argc, i,
		"Wrong number of elements in the stack.");
}

static void	test_rev_rotate_NULL(void)
{
	t_stack	stack_a;
	char	name;

	name = 'a';
	stack_a.name = name;
	stack_a.stack = NULL;
	ps_rev_rotate(&stack_a);
	TEST_ASSERT_NULL(stack_a.stack);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_input_regularInput);
	RUN_TEST(test_input_intLimits);
	RUN_TEST(test_input_negativeNumbers);
	RUN_TEST(test_input_duplicates);
	RUN_TEST(test_input_notNumber);
	RUN_TEST(test_input_notNumber2);
	RUN_TEST(test_input_notNumber3);
	RUN_TEST(test_input_underInt);
	RUN_TEST(test_input_overInt);
	RUN_TEST(test_swap);
	RUN_TEST(test_swap_secondNULL);
	RUN_TEST(test_swap_firstNULL);
	RUN_TEST(test_push);
	RUN_TEST(test_push_fromNULL);
	RUN_TEST(test_rotate);
	RUN_TEST(test_rotate_one);
	RUN_TEST(test_rotate_NULL);
	RUN_TEST(test_rev_rotate);
	RUN_TEST(test_rev_rotate_one);
	RUN_TEST(test_rev_rotate_NULL);
	return (UNITY_END());
}
