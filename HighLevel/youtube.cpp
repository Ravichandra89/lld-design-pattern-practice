/**
 * Designing CAP for youtube - which is massive video sharing platform.
 * 
 *  - Indentifying the System priorities:
 *    - Availability: User need that system must accessible and operational 24/7.
 *   - Partition Tolerance: It ensure that system must be able even there is network partition among servers.
 * 
 */

 /**
  * Choose Right Data Store: 
  *     - System need to handle large volume of data in distributed system so we need the Amazon DynamoDB & Cossandra DB. 
  *     - Both are highly available and partition tolerant.
  *     - Can handle high throughput for read and write operations.
  */

/**
 * Scalability & Redundancy:
 *      - We need to adopt the storage distributed system which implement the Horizontal scalling(adding extra nodes to the cluster).
 *      - Also Replicating those data across multiple geographical locations - so that data must be durable and available .
 */

 /**
  * Optimise for Data Inconsistency:
  *     - When user upload the video - the server should replicate this data across multiple nodes asynchrnously so that system made the eventually consistent.
  */

/**
 * Use Caching and Content Delivery Network (CDN): 
 *   - To improve the latency and performance of video streaming. We just cache the frequently accessed video content. 
 *  - CDN will distribute the video content across multiple geographical locations.
 */

/**
 * Monitoring and Adopting + Alerting: 
 *      - Keep on monitoring the system performance, and availability.
 *     - Set up the alerting mechanism to notify the engineering team in case of any issues
 */