/*
 * LightsAgent.h
 *
 *  Created on: 22 Mar 2025
 *      Author: jondurrant
 */

#ifndef FIRMWARE_WHEEL_SRC_LIGHTSAGENT_H_
#define FIRMWARE_WHEEL_SRC_LIGHTSAGENT_H_

#include "uRosEntities.h"

extern "C"{
#include <std_msgs/msg/string.h>
#include <std_msgs/msg/header.h>
}

#define LIGHTS_AGENT_BUFFER_SIZE 256
#define LIGHTS_AGENT_MAX_KEYS 5

//Commands
#define LIGHTS_AGENT_HEADLIGHT 	"head"
#define LIGHTS_AGENT_TAILLIGHT 		"tail"
#define LIGHTS_AGENT_COLOUR			"colour"
#define LIGHTS_AGENT_PATTERN			"pattern"




class LightsAgent  : public  uRosEntities  {
public:
	LightsAgent();
	virtual ~LightsAgent();

	/***
	 * Create the entities (Publishers)
	 * @param node
	 * @param support
	 */
	virtual void createEntities(rcl_node_t *node, rclc_support_t *support);

	/***
	 * Destroy the entities
	 * @param node
	 * @param support
	 */
	virtual void destroyEntities(rcl_node_t *node, rclc_support_t *support);

	/***
	 * Return the number of entities
	 * @return
	 */
	virtual uint getCount();

	/***
	 * Return the number of handles needed by the executor
	 * @return
	 */
	virtual uint getHandles();


	/***
	 * Add subscribers, guards and timers to the executor
	 * @param executor
	 */
	virtual void addToExecutor(rclc_executor_t *executor);


protected:

	/***
	 * Handle subscription msg
	 * @param msg
	 * @param localContext
	 */
	virtual void handleSubscriptionMsg(const void* msg, uRosSubContext_t* Context);


	virtual void setHeadlights(double head);

	virtual void setTaillights(double tail);

	virtual void setColour(const char *hexString);

	virtual void setPattern(int p);

private:
	void initMsg();

	rcl_subscription_t 			xSubLights;
	uRosSubContext_t   		xSubLightsContext;
	std_msgs__msg__String xLightsMsg;

	char xBuffer[LIGHTS_AGENT_BUFFER_SIZE];

	static const char *X_TOPIC_LEFT;
	static const char *X_TOPIC_RIGHT;
};

#endif /* FIRMWARE_WHEEL_SRC_LIGHTSAGENT_H_ */
