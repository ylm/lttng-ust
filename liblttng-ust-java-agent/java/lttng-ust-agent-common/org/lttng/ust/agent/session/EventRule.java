/*
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * Copyright (C) 2015 EfficiOS Inc.
 * Copyright (C) 2015 Alexandre Montplaisir <alexmonthy@efficios.com>
 */

package org.lttng.ust.agent.session;

/**
 * Event filtering rule present in a tracing session.
 *
 * It typically comes from a "lttng enable-event" command, and contains a
 * domain, event name, log level and filter string.
 *
 * @author Alexandre Montplaisir
 */
public class EventRule {

	private final String eventName;
	private final LogLevelSelector logLevelSelector;
	private final String filterString;

	/**
	 * Constructor.
	 *
	 * @param eventName
	 *            The name of the tracepoint
	 * @param logLevelSelector
	 *            The log level of the event rule
	 * @param filterString
	 *            The filtering string. May be null if there is no extra filter.
	 */
	public EventRule(String eventName, LogLevelSelector logLevelSelector, String filterString) {
		this.eventName = eventName;
		this.logLevelSelector = logLevelSelector;
		this.filterString = filterString;
	}

	/**
	 * Get the event name of this rule.
	 *
	 * @return The event name
	 */
	public String getEventName() {
		return eventName;
	}

	/**
	 * Get the log level filter configuration of the rule.
	 *
	 * @return The log level selector
	 */
	public LogLevelSelector getLogLevelSelector() {
		return logLevelSelector;
	}

	/**
	 * Get the filter string associated with this rule.
	 *
	 * @return The filter string, may be null for no filter string.
	 */
	public String getFilterString() {
		return filterString;
	}

	// ------------------------------------------------------------------------
	// Methods from Object
	// ------------------------------------------------------------------------

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((eventName == null) ? 0 : eventName.hashCode());
		result = prime * result + ((filterString == null) ? 0 : filterString.hashCode());
		result = prime * result + ((logLevelSelector == null) ? 0 : logLevelSelector.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (getClass() != obj.getClass()) {
			return false;
		}
		EventRule other = (EventRule) obj;

		if (eventName == null) {
			if (other.eventName != null) {
				return false;
			}
		} else if (!eventName.equals(other.eventName)) {
			return false;
		}
		/* else, continue */

		if (filterString == null) {
			if (other.filterString != null) {
				return false;
			}
		} else if (!filterString.equals(other.filterString)) {
			return false;
		}
		/* else, continue */

		if (logLevelSelector == null) {
			if (other.logLevelSelector != null) {
				return false;
			}
		} else if (!logLevelSelector.equals(other.logLevelSelector)) {
			return false;
		}
		/* else, continue */

		return true;
	}

	@Override
	public String toString() {
		return "Event name = " + getEventName() +
		", Log level selector = (" + getLogLevelSelector().toString() + ")" +
		", Filter string = " + getFilterString();
	}
}
