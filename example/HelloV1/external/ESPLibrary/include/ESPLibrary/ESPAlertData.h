/*
 * Copyright(c) 2016 Valentine Research, Inc
 * This file is part of the ESP Library, which is licensed under the MIT license.
 * You should have received a copy of the MIT license along with this file. If not, see http://opensource.org/licenses/MIT
 */

#import <Foundation/Foundation.h>
#import "ESPFrequency.h"

typedef enum
{
	//! The band of an alert data packet with invalid band data
	ESPAlertBandInvalid = -1,
	//! "Laser" band is currently not supported by the V1
	ESPAlertBandLaser = 0x01,
	ESPAlertBandKa = 0x02,
	ESPAlertBandK = 0x04,
	ESPAlertBandX = 0x08,
	ESPAlertBandKu = 0x10,
} ESPAlertBand;

typedef enum
{
	//! The direction of an alert data packet with invalid direction data
	ESPAlertDirectionInvalid = -1,
	ESPAlertDirectionFront = 0x04,
	ESPAlertDirectionSide = 0x02,
	ESPAlertDirectionRear = 0x01
} ESPAlertDirection;



//! Represents an alert sent from an ESP devices
@interface ESPAlertData : NSObject

-(id)init __attribute((unavailable("You must use initWithData: or initWithAlertData:")));

/*! Initializes the alert from a received packet's payload
	@param data the payload data of a respAlertData packet
	@returns a newly initialized alert */
-(id)initWithData:(NSData*)data;
/*! Initializes a new alert by copying information from an existing alert
	@param alert the alert to copy from
	@returns a newly initialized alert */
-(id)initWithAlertData:(ESPAlertData*)alert;

/*! Tells if the given alert is equal to this alert
	@param alertData the alert to compare
	@returns YES if the alerts are equal, or NO if they are not equal */
-(BOOL)isEqualToAlertData:(ESPAlertData*)alertData;

/*! Tells if the given alert is within the deviance window of this alert
	@param alert the alert to compare
	@returns YES if the alert is within the deviance window, NO if it is not */
-(BOOL)isWithinDevianceWindow:(ESPAlertData*)alert;

//! The full payload data of the alert
@property (nonatomic, readonly) NSData* data;

//! The number of alerts in the alert table
@property (nonatomic, readonly) NSUInteger count;
//! The index of the alert in the alert table
@property (nonatomic, readonly) NSUInteger index;

//! The frequency of the alert
@property (nonatomic, readonly) ESPFrequencyMHz frequency;

//! The front signal strength (0-255)
@property (nonatomic, readonly) NSUInteger frontSignalStrength;
//! The rear signal strength (0-255)
@property (nonatomic, readonly) NSUInteger rearSignalStrength;

//! The bargraph strength indicator strength (0-8)
@property (nonatomic, readonly) NSUInteger bargraphSignalStrength;

//! Tells if this alert is a priority alert
@property (nonatomic, readonly, getter=isPriority) BOOL priority;

//! The direction of the alert
@property (nonatomic, readonly) ESPAlertDirection direction;
//! The band of the alert
@property (nonatomic, readonly) ESPAlertBand band;

//! Represents how far an alert may deviate in its frequency
@property (nonatomic, readonly) ESPFrequencyMHz deviance;

//! The alert frequency plus deviance
@property (nonatomic, readonly) ESPFrequencyMHz upperWindowEdge;
//! The alert frequency minus devience
@property (nonatomic, readonly) ESPFrequencyMHz lowerWindowEdge;

@end
