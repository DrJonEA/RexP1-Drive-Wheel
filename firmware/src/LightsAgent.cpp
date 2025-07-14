/*
 * LightsAgent.cpp
 *
 *  Created on: 22 Mar 2025
 *      Author: jondurrant
 */

#include "LightsAgent.h"
#include "ConfigEntity.h"
#include "AstroDroidConfig.h"
#include "tiny-json.h"
#include "NVSJson.h"

#include "pico/stdlib.h"
#include "hardware/pwm.h"

 const char * LightsAgent::X_TOPIC_LEFT= "/Astro/lightsLEFT";
 const char * LightsAgent::X_TOPIC_RIGHT = "/Astro/lightsRIGHT";

LightsAgent::LightsAgent() {
	initMsg();

	gpio_init(HEADLIGHT);
	gpio_set_function(HEADLIGHT, GPIO_FUNC_PWM);
	pwm_set_gpio_level(HEADLIGHT, 0);
	uint slice_num = pwm_gpio_to_slice_num(HEADLIGHT);
	pwm_set_enabled(slice_num, true);

	gpio_init(TAILLIGHT);
	gpio_set_function(TAILLIGHT, GPIO_FUNC_PWM);
	pwm_set_gpio_level(TAILLIGHT, 0);
	slice_num = pwm_gpio_to_slice_num(TAILLIGHT);
	pwm_set_enabled(slice_num, true);
}

LightsAgent::~LightsAgent() {
	// TODO Auto-generated destructor stub
}

/***
 * Create the publishing entities
 * @param node
 * @param support
 */
void LightsAgent::createEntities(rcl_node_t *node, rclc_support_t *support){
	rcl_ret_t res;

	NVSJson * nvs = NVSJson::getInstance();

	bool left;
	const char *topic = NULL;
	nvs->get_bool(CONFIG_LEFT,  &left);
	if (left){
		topic = LightsAgent::X_TOPIC_LEFT;
	} else {
		topic = LightsAgent::X_TOPIC_RIGHT;
	}
	res = rclc_subscription_init_default(
			  &xSubLights,
			  node,
			 ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),
			  topic
			  );

	if (res != RCL_RET_OK){
		printf("ERROR: LightsAgent::createEntities failed to init subscriber \n");
	}

}

/***
 * Destroy the publishing entities
 * @param node
 * @param support
 */
void LightsAgent::destroyEntities(rcl_node_t *node, rclc_support_t *support){
	rcl_subscription_fini(&xSubLights, 	node);
}


/***
 * Provide a count of the number of entities
 * @return number of entities >=0
 */
uint LightsAgent::getCount(){
	return 1;
}

/***
 * Return the number of handles needed by the executor
 * @return
 */
uint LightsAgent::getHandles(){
	uint res = 1;
	return res;
}

/***
 * Add subscribers, guards and timers to the executor
 * @param executor
 */
void LightsAgent::addToExecutor(rclc_executor_t *executor){

	buildContext(&xSubLightsContext, NULL);
	rcl_ret_t res = rclc_executor_add_subscription_with_context(
			executor,
			&xSubLights,
			&xLightsMsg,
			uRosEntities::subscriptionCallback,
			&xSubLightsContext,
			ON_NEW_DATA);

	if (res != RCL_RET_OK){
		printf("ERROR: ConfigEntity::addToExecutor failed to add executor \n");
	}
}

/***
 * Handle subscription msg
 * @param msg
 * @param localContext
 */
void LightsAgent::handleSubscriptionMsg(
		const void* msg,
		uRosSubContext_t* context){

	printf("LightsAgent::handleSubscriptionMsg\n");

	if (context == &xSubLightsContext){
		std_msgs__msg__String * pStringMsg = (std_msgs__msg__String *) msg;

		json_t mem[LIGHTS_AGENT_MAX_KEYS];
		json_t const* json = json_create( pStringMsg->data.data, mem, sizeof mem / sizeof *mem );
		if ( !json ) {
			printf("Error json create.\n");
			return ;
		}
		json_t const *cmd ;

		//Headlights
		cmd = json_getProperty(json, LIGHTS_AGENT_HEADLIGHT);
		if (cmd != NULL){
			if (json_getType(cmd) == JSON_REAL){
				double head = json_getReal(cmd);
				setHeadlights(head);
			}
		}

		//Taillights
		cmd = json_getProperty(json, LIGHTS_AGENT_TAILLIGHT);
		if (cmd != NULL){
			if (json_getType(cmd) == JSON_REAL){
				double tail = json_getReal(cmd);
				setTaillights(tail);
			}
		}

		//Colour
		cmd = json_getProperty(json, LIGHTS_AGENT_COLOUR);
		if (cmd != NULL){
			if (json_getType(cmd) == JSON_TEXT){
				const char *s = json_getValue(cmd);
				setColour(s);
			}
		}

		//Pattern
		cmd = json_getProperty(json, LIGHTS_AGENT_PATTERN);
		if (cmd != NULL){
			if (json_getType(cmd) == JSON_INTEGER){
				int p = json_getInteger(cmd);
				setPattern(p);
			}
		}



	}
}

void LightsAgent::initMsg(){
	xLightsMsg.data.data = xBuffer;
	xLightsMsg.data.capacity = LIGHTS_AGENT_BUFFER_SIZE;
}

void LightsAgent::setHeadlights(double head){
	uint16_t level;
	if (head >= 1.0){
		level = 0xffff;
	} else {
		double f = head * 255.0;
		level = (int)f;
		level = level * level;
	}
	pwm_set_gpio_level(HEADLIGHT, level);
}

void LightsAgent::setTaillights(double tail){
	uint16_t level;
	if (tail >= 1.0){
		level = 0xffff;
	} else {
		double f = tail * 255.0;
		level = (int)f;
		level = level * level;
	}
	pwm_set_gpio_level(TAILLIGHT, level);
}

void LightsAgent::setColour(const char *hexString){

}

void LightsAgent::setPattern(int p){

}
