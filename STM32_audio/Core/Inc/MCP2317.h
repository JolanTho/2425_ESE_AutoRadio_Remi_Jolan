#ifndef MCP2317_H_
#define MCP2317_H_

void MCP17023_init(void);
void MCP17023_write_register(uint8_t addr, uint8_t value);
void MCP17023_set_led (uint8_t addrled);
void MCP17023_chenillard(char **argv);
int MCP17023_led(char **argv);



#endif /* CALLBACK_H_ */


