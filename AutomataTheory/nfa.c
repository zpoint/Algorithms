#include <stdio.h>
#include <stdlib.h>

enum STATE {A, B, C, EPLISON};

struct extendable_state
{
		size_t state_size;
		size_t capacity;
		enum STATE *states;
};

int add_state(struct extendable_state *ext_states, enum STATE state_to_add)
{
		for (size_t i = 0; i < ext_states->state_size; ++i)
		{
				if (ext_states->states[i] == state_to_add)
						return 0;
		}
		if (ext_states->capacity <= ext_states->state_size)
		{
				if (ext_states->capacity > 0)
						ext_states->capacity *= 2;
				else
						ext_states->capacity = 2;

				enum STATE *new_states = malloc(sizeof(enum STATE) * ext_states->capacity);
				for (size_t i = 0; i < ext_states->state_size; ++i)
						new_states[i] = ext_states->states[i];
				free(ext_states->states);
				ext_states->states = new_states;
		}
		ext_states->states[ext_states->state_size] = state_to_add;
		ext_states->state_size += 1;
		return 1;
}

int remove_state(struct extendable_state *ext_states, enum STATE state_to_remove)
{
		for (size_t i = 0; i < ext_states->state_size; ++i)
		{
				if (ext_states->states[i] == state_to_remove)
				{
						for (size_t j = i+1; j < ext_states->state_size; ++j)
								ext_states->states[j-1] = ext_states->states[j];
						return 1;
				}
		}
		return 0;
}

struct extendable_state copy_states(struct extendable_state states)
{
		struct extendable_state new_state;
		new_state.state_size = new_state.capacity = 0;
		for (size_t i = 0; i < states.state_size; ++i)
				add_state(&new_state, states.states[i]);
		return new_state;
}


int T_A(int c, struct extendable_state *current_states)
{
		if (c == '0')
		{
				add_state(current_states, A);
				add_state(current_states, B);
				return 1;
		}
		else if (c == '1')
		{
				add_state(current_states, A);
				return 1;
		}
		return 0;
}

int T_B(int c, struct extendable_state *current_states)
{
		if (c == '0')
		{
				return 1;
		}
		else if (c == '1')
		{
				add_state(current_states, C);
		}
		return 0;
}

int T_C(int c, struct extendable_state *current_states)
{
		if (c == '0')
		{
				add_state(current_states, C);
				return 1;
		}
		else if (c == '1')
		{
				add_state(current_states, C);
				return 1;
		}
		return 0;
}

int main()
{
		struct extendable_state current_states;
		current_states.state_size = current_states.capacity = 0;
		add_state(&current_states, A); // add begin state
		int c;
		printf("Please enter strings only contains 0, 1, I will match all string contain '01'\n");
		while ((char)(c = getchar()) != EOF)
		{
				struct extendable_state temp_state = copy_states(current_states);
				free(current_states.states);
				current_states.state_size = current_states.capacity = 0;
				
				if (c == '\n')
				{
						// current input done
						int accepted = 0;
						for (size_t i = 0; i < temp_state.state_size; ++i)
						{
								if (temp_state.states[i] == C)
								{
										accepted = 1;
										break;
								}
						}
						if (accepted)
								printf("Accepted\n");
						else
								printf("Not accepted\n");

						add_state(&current_states, A);
						continue;
				}

				// printf("temp_state.state_size: %d", temp_state.state_size);
				for (size_t i = 0; i < temp_state.state_size; ++i)
				{
						enum STATE current_in_state = current_states.states[i];
						// printf("current_in_state: ");
						switch(current_in_state)
						{
								case A: 
										T_A(c, &current_states);
										// printf("A ");
										break;
								case B:
										T_B(c, &current_states);
										// printf("B ");
										break;
								case C:
										T_C(c, &current_states);
										// printf("C ");
										break;
								default:
										printf("Error, Unknown states");
						}
						// printf("\n");
				}
		}
		return 0;
}
