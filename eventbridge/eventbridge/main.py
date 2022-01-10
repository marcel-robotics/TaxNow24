"""Console script for eventbridge."""
import logging
import os
from typing import Dict, Any

import sys
import click
from confluent_kafka import KafkaException

from eventbridge.consumer import persist_events
from eventbridge.datalake import load_raw_data
from eventbridge.producer import publish_raw_events, create_topic


def publish_events(config: Dict[str, Any], topic: str, raw_events_file: str) -> int:
    logging.info("Starting eventbridge")

    logging.info("Loading raw events file from: %s", raw_events_file)
    raw_events = load_raw_data(raw_events_file)
    logging.info("Done loading raw events")

    logging.info("Start creating topic")
    create_topic(topic)
    logging.info("Done creating topic")

    logging.info("Start publishing events")
    publish_raw_events(config, topic, raw_events)
    logging.info("Done publishing events")

    logging.info("Stopping eventbridge")
    return 0


def consume_events(config: Dict[str, Any], topic: str) -> int:
    logging.info("Starting eventbridge")

    logging.info("Starting consumer")
    persist_events(config, topic)

    logging.info("Stopping eventbridge")
    return 0


@click.command()
@click.option("--raw-events-file", help="path of the raw events csv file", type=str)
def main(raw_events_file: str) -> int:
    config = {"bootstrap.servers": "kafka:9092,localhost:29092"}
    topic = "pricing_events"
    try:
        if os.getenv("CONSUME"):
            return consume_events(config, topic)
        return publish_events(config, topic, raw_events_file)
    except KafkaException as error:
        logging.error("Was not able to publish events: %s", error)
        return 1


# pylint: disable=E1120
if __name__ == "__main__":
    sys.exit(main())
