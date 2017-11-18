#include <stdio.h>
#include <stdlib.h>

enum STATE {A, B, C, EPSILON};

struct extendable_state
{
		int state_size;
		int capacity;
		enum STATE *states;
};

int add_state(struct extendable_state ext_states, enum STATE state_to_add)
{
		for (size_t i = 0; i < ext_states.state_size; ++i)
		{
				if (ext_states.states[i] == state_to_add)
						return 0;
		}
		if (ext_states.capacity <= ext_states.state_size)
		{
				ext_states.capacity *= 2;
				enum STATE *new_states = malloc(sizeof(enum STATE) * ext_states.capacity);
				for (size_t i = 0; i < ext_states.state_size; ++i)
						new_states[i] = ext_states.states[i];
				free(ext_states.states);
				ext_states.states = new_states;
		}
		ext_states.states[ext_states.state_size] = state_to_add;
		ext_states.state_size += 1;
		return 1;
}

int remove_state(struct extendable_state ext_states, enum STATE state_to_remove)
{
		for (size_t i = 0; i < ext_states.state_size; ++i)
		{
				if (ext_states.states[i] == state_to_remove)
				{
						for (size_t j = i+1; j < ext_states.state_size; ++j)
								ext_states.states[j-1] = ext_states.states[j];
						return 1;
				}
		}
		return 0;
}

int main()
{
		return 0;
}
